#include <bits/stdc++.h>
#define rep(a,n) for (int a = 0; a < (n); ++a)
using namespace std;
using ll = long long;
typedef pair<int,int> P;
typedef pair<ll,P> PP;
typedef vector<vector<int> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;

int main(){
    ll n;
    cin >> n;
    if(n==0){
        cout << 0 << endl;
        return 0;
    }
    string ans = "";
    while(n!=0){
        ll amari = abs(n%2);
        ans += to_string(amari);
        if(n==-1){
            ans += '1';
            break;
        }
        if(n<0){
            if(amari==1){
                n = -(n-2)/2;
            }
            else{
                n = n/-2;
            }
        }
        else n=-n/2;
    }
    reverse(ans.begin(),ans.end());
    cout << ans << endl;
    return 0;
}

