#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
#define REP(i, n) for(ll i=0; i<(ll)(n); i++)
#define REPD(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=a; (ll)(b)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))


int main(){
    int n;  cin >> n;
    vector<ll> x(n), y(n), h(n);
    REP(i, n)   cin >> x.at(i) >> y.at(i) >> h.at(i);


    
    REP(i, 101){
        REP(j, 101){
            ll H=0; 
            bool flag=true; 
            priority_queue<ll> que;
            REP(k, n){
                ll tmp = abs(x[k]-i)+abs(y[k]-j);
                if(h[k]==0){
                    que.push(tmp);
                    continue;
                }

                if(0<H && H != h[k]+tmp){
                    flag = false;
                    break;
                }
                H = h[k]+tmp;
            }
            while(flag && !que.empty()){
                if(que.top()<H) flag = false;
                que.pop();
            }

            if(flag){    
                cout << i << ' ' << j << ' ' << H << endl;
                return 0;
            }
        

        } 
    }
}