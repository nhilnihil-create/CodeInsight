#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<vector<int> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    int n,k;
    cin >> n >> k;
    ll ans = 0;
    ll s = n/k;
    ans+=pow(s,3);
    if(k%2==1){
        cout << ans << endl;
        return 0;
    }
    if(n-s*k>=k/2){
        ans+=pow(s+1,3);
    }
    else{
        ans+=pow(s,3);
    }
    cout << ans << endl;
    return 0;
}