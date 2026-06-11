#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    vector<pll> sushies;// おいしさ、ネタIDの順
    for (int i = 0; i < N; i++)
    {
        ll T, D;
        cin >> T >> D;
        sushies.emplace_back(D, T);
    }
    sort(sushies.begin(), sushies.end(), greater<pll>());
    //初め貪欲にとる
    ll typeNum = 0;
    ll basicPoint = 0;
    vector<ll> typeCount(N + 1, 0);
    vector<pll> currentSushies(0);
    for(int i = 0; i < K; i++)
    {
        pll sushi = sushies.at(i);
        ll point, type;
        tie(point, type) = sushi;
        if(typeCount.at(type) == 0)
        {
            typeNum++;
        }
        typeCount.at(type)++;
        currentSushies.push_back(sushi);
        basicPoint += point;
    }
    ll answer = basicPoint + typeNum * typeNum;
    //1種類ずつ可能なラインまで増やし、既存の最高値を超えたら更新
    int checkIndex = K;
    int currentSushiIndex = K - 1;
    for(int i = typeNum + 1; i <= K; i++)
    {
        //貪欲で保持した寿司から種類数を崩さないように一個除去(必ず見つかる見込み)
        while(true)
        {
            pll sushi = currentSushies.at(currentSushiIndex);
            currentSushiIndex--;
            ll point, type;
            tie(point, type) = sushi;
            if(typeCount.at(type) == 1)
            {
                continue;
            }
            typeCount.at(type)--;
            basicPoint -= point;
            break;
        }
        //他の種類の寿司を追加
        while(checkIndex < N)
        {
            pll sushi = sushies.at(checkIndex);
            ll point, type;
            tie(point, type) = sushi;
            if(typeCount.at(type) > 0)
            {
                checkIndex++;
                continue;
            }
            typeCount.at(type)++;
            typeNum++;
            basicPoint += point;
            checkIndex++;
            break;
        }
        //状況次第でcheckIndex == Nでsushiが一個removeされたのみで来ることがあるが
        //maxより少なくなるため問題ない
        answer = max(answer, basicPoint + typeNum * typeNum);
        if(checkIndex == N)
        {
            //これ以上種類を増やせない
            break;
        }
    }

    cout << answer << endl;
    return 0;
}
