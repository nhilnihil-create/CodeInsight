#include <bits/stdc++.h>
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define per(i, n, s) for (int i = (n-1); i >= (int)(s); i--)
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<x<<endl
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
const ll LINF = LLONG_MAX;
const int INF = INT_MAX;

int main() {
    int n; cin>>n;
    rep(i,0,30){
        if((n-4*i)%7==0){
            cout<<"Yes"<<endl;
            return 0;
        }
        if(i*4>n) break;
    }
    cout<<"No"<<endl;
}
