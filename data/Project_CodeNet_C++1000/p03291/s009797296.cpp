#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    ll MOD = 1e9 + 7;
    ll hatenaCount = 0;
    vector<ll> ruisekiHatena(S.size() + 1);
    vector<ll> ruisekiA(S.size() + 1);
    vector<ll> ruisekiC(S.size() + 1);
    for (int i = 0; i < S.size(); i++)
    {
        ruisekiHatena.at(i + 1) = ruisekiHatena.at(i);
        ruisekiA.at(i + 1) = ruisekiA.at(i);
        ruisekiC.at(i + 1) = ruisekiC.at(i);
        if (S.at(i) == '?')
        {
            ruisekiHatena.at(i + 1)++;
        }
        else if (S.at(i) == 'A')
        {
            ruisekiA.at(i + 1)++;
        }
        else if (S.at(i) == 'C')
        {
            ruisekiC.at(i + 1)++;
        }
    }
    ll tripleHatenaToorisuu = 1;// 一つの?をBと決めたときの左の?を'A'、別の?を'C'と決めた時の通り数(全通りの1/27になる)
    for (int i = 1; i <= ruisekiHatena.at(S.size()) - 3; i++)
    {
        tripleHatenaToorisuu = (tripleHatenaToorisuu * 3) % MOD;
    }
    ll doubleHatenaToorisuu = 1; // 一つの?をBと決めたときの左の?か右の?どちらか一つを'A'または'C'と決めた時の通り数(逆は確定とする)(全通りの1/9になる)
    for (int i = 1; i <= ruisekiHatena.at(S.size()) - 2; i++)
    {
        doubleHatenaToorisuu = (doubleHatenaToorisuu * 3) % MOD;
    }
    ll hatenaToorisuu = 1; //ひとつの?をBと決めたとき、AまたはCが確定している時の通り数(全通りの1/3)
    for (int i = 1; i <= ruisekiHatena.at(S.size()) - 1; i++)
    {
        hatenaToorisuu = (hatenaToorisuu * 3) % MOD;
    }
    ll toorisuu = 1; //ABC全部確定の時の通り数(全通り数になる)
    for (int i = 1; i <= ruisekiHatena.at(S.size()); i++)
    {
        toorisuu = (toorisuu * 3) % MOD;
    }
    ll answer = 0;
    for (int i = 1; i < S.size() - 1; i++)
    {
        if (S.at(i) == 'B')
        {
            //確定Aと確定Cの分
            answer = (answer + toorisuu * ruisekiA.at(i) * (ruisekiC.at(S.size()) - ruisekiC.at(i + 1))) % MOD;
            //確定Aと?がCの分
            answer = (answer + hatenaToorisuu * ruisekiA.at(i) * (ruisekiHatena.at(S.size()) - ruisekiHatena.at(i + 1))) % MOD;
            //?がAと確定Cの分
            answer = (answer + hatenaToorisuu * ruisekiHatena.at(i) * (ruisekiC.at(S.size()) - ruisekiC.at(i + 1))) % MOD;
            //?がAと?がCの分
            answer = (answer + doubleHatenaToorisuu * ruisekiHatena.at(i) * (ruisekiHatena.at(S.size()) - ruisekiHatena.at(i + 1))) % MOD;
        }
        else if (S.at(i) == '?')
        {
            //確定Aと確定Cの分
            answer = (answer + hatenaToorisuu * ruisekiA.at(i) * (ruisekiC.at(S.size()) - ruisekiC.at(i + 1))) % MOD;
            //確定Aと?がCの分
            answer = (answer + doubleHatenaToorisuu * ruisekiA.at(i) * (ruisekiHatena.at(S.size()) - ruisekiHatena.at(i + 1))) % MOD;
            //?がAと確定Cの分
            answer = (answer + doubleHatenaToorisuu * ruisekiHatena.at(i) * (ruisekiC.at(S.size()) - ruisekiC.at(i + 1))) % MOD;
            //?がAと?がCの分
            answer = (answer + tripleHatenaToorisuu * ruisekiHatena.at(i) * (ruisekiHatena.at(S.size()) - ruisekiHatena.at(i + 1))) % MOD;
        }
    }
    cout << answer << endl;
    return 0;
}
