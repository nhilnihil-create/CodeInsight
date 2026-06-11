#include <bits/stdc++.h>
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end() 
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define INF 1000000000
using namespace std;
typedef long long ll;

int main() {
    int D, G;
    cin >> D >> G;

    vector<int> p(D);
    vector<int> c(D);
    REP(i, D){
        cin >> p[i] >> c[i];
    }

    int ans = 1e+9;
    for(int pos = 0; pos < (1<<D); pos++){
        int s = 0, num = 0, rest_max = -1;
        REP(i, D){
            if (1 & pos >> i){
                s += 100 * (i+1) * p[i] + c[i]; //ボーナス迄考慮する
                num += p[i];
            }
            else{
                rest_max = i;
            }
        }
        if(s < G){
            int s1 = 100*(rest_max + 1);
            int need = (G - s + s1 - 1)/s1;
            if(need >= p[rest_max]){
                continue;   //選ばなかった中でも最大の者で満たせないならcontinue
            }
            num += need;    //満たせるならその回数を加算
        }
        ans = min(ans, num);
    }
    cout << ans << endl;
}