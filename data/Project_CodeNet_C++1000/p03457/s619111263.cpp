#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    vector<int> t(n), x(n),y(n);
    rep(i,n) cin >> t[i] >> x[i] >> y[i];
    int nowx = 0, nowy = 0;
    rep(i,n){
        if(i == 0){
            if(x[i] + y[i] > t[i]){
                cout << "No" << endl;
                return 0;
            }else{
                if((x[i] + y[i])%2 == 0 && t[i]%2 == 0) continue;
                else if((x[i] + y[i])%2 != 0 && t[i]%2 != 0) continue;
                else{
                    cout << "No" << endl;
                    return 0;
                }
            }
        }else{
            if(abs(x[i]  + y[i] - x[i-1] - y[i-1]) > t[i] - t[i-1]){
                cout << "No" << endl;
                return 0;
            }else{
                if(abs(x[i]  + y[i] - x[i-1] - y[i-1])%2 == 0 && (t[i]-t[i-1])%2 == 0) continue;
                else if(abs(x[i]  + y[i] - x[i-1] - y[i-1])%2 != 0 && (t[i]-t[i-1])%2 != 0) continue;
                else{
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;
    return 0; 
}