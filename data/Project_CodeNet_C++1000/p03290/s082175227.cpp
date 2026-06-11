#include <bits/stdc++.h>
#include <queue>
#define REP(i, n) for (ll i = 1; i <= n; i++)
#define rep(i, n) for (ll i = 0; i < n; i++)
#define ll long long
#define ld long double
using namespace std;

int main()
{
    ll D, G;
    cin >> D >> G;
    vector<ll> p(D);
    vector<ll> c(D);
    vector<ll> perfectScores(D);
    ll ans = INT_MAX;
    rep(i, D)
    {
        cin >> p[i];
        cin >> c[i];
    }

    REP(i,D){
        ll score = 0;
        score += 100 * i * p[i - 1];
        score += c[i - 1];
        perfectScores[i - 1] = score;
    }

    for(int tmp = 0; tmp < (1 << D);tmp++){
        bitset<10> bs(tmp);
        string cut = bs.to_string();
        cut = cut.substr(10 - D);
        //cout << cut << endl;
        ll currentScore = 0;
        ll count = 0;

        rep(i,D){
            if(cut.at(i) == '1'){
                currentScore += perfectScores[i];
                count += p[i];
            }
        }
        rep(i,D){
            rep(j,p[D - i - 1]){
                if(cut.at(D - i - 1) == '0'){
                    if(currentScore < G){
                        currentScore += 100 * (D - i);
                        count += 1;
                    }
                }
            }
        }
        ans = min(ans,count);
    }
    cout << ans << endl;
}
