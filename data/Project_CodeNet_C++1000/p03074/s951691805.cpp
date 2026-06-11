#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    int N, K;
    string S;
    cin >> N >> K;
    cin >> S;

    // (0が連続する区間の始点, 0が連続する区間の終点,　始点の左に何個1が連続しているか, 終点の右に何個1が連続しているか)
    vector<tuple<int, int, int, int>> zeroBlock;
    bool isZero = S[0] == '0';
    bool isOne = S[0] == '1';
    int contZero = isZero ? 1 : 0;
    int contOne = isOne ? 1 : 0;
    int stZero, endZero;
    int prevContOne = 0;
    for (int i = 1; i < N; ++i)
    {
        if (isZero)
        {
            if (S[i] == '0')
            {
                contZero++;
            }
            else
            {
                isZero = false;
                isOne = true;
                stZero = i - contZero;
                endZero = i - 1;
                prevContOne = contOne;
                contOne = 1;
            }
        }
        else if (isOne)
        {
            if (S[i] == '0')
            {
                isZero = true;
                isOne = false;
                if (contZero != 0)
                {
                    zeroBlock.push_back(make_tuple(stZero, endZero, prevContOne, contOne));
                }
                contZero = 1;
            }
            else
            {
                contOne++;
            }
            
        }
    }
    if (S[N - 1] == '0')
    {
        stZero = N - contZero;
        endZero = N - 1;
        zeroBlock.push_back(make_tuple(stZero, endZero, contOne, 0));
    }
    else
    {
        if (contZero != 0) zeroBlock.push_back(make_tuple(stZero, endZero, prevContOne, contOne));
    }
    
    int ans;
    if (zeroBlock.size() <= K)
    {
        ans = N;
    }
    else
    {
        ans = -1;
        for (int i = 0; i + K - 1 < zeroBlock.size(); ++i) 
        {
            int current = get<1>(zeroBlock[i + K - 1]) - get<0>(zeroBlock[i]) + 1 + get<2>(zeroBlock[i]) + get<3>(zeroBlock[i + K - 1]);
            ans = max(ans, current);
        }
    }
    
    cout << ans << endl;
}
