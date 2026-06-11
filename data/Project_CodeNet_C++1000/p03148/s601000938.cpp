#include <bits/stdc++.h>

#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define ACC(c) (accumulate(ALL(c), 0LL))
#define PRINT(x) cout << (x) << "\n"

using namespace std;
using ll = long long;
using pint = pair<int, int>;
using pll = pair<ll, ll>;

inline int in(int& a) {return scanf("%d", &a);}
auto pint_compare = [](pint x, pint y) -> bool{return (x.first < y.first);};


int N, K;
pll sushi[100000];
map<int, int> m;


signed main(){
    cin >> N >> K;
    ll t, d;
    REP(i, N){
        cin >> t >> d;
        t--;
        sushi[i] = {d, t};
    }
    sort(sushi, sushi + N, greater<pint>());
    ll var = 0;
    ll ans, sum = 0;
    REP(i, K){
        sum += sushi[i].first;
        m[sushi[i].second]++;
        if(m[sushi[i].second] == 1) var++;
    }
    sum += var * var;
    ans = sum;
    int j = K - 1;
    FOR(i, K, N){   
        if(m[sushi[i].second] > 0) continue;
        while(m[sushi[j].second] <= 1 && j >= 0) j--;
        if(j < 0) break;
        m[sushi[i].second]++;
        m[sushi[j].second]--;
        sum = sum + sushi[i].first - sushi[j].first + 2 * var + 1;
        j--; var++;
        ans = max(ans, sum);
    }
    PRINT(ans);
    return 0;
}