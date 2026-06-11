#include <bits/stdc++.h>
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define pb push_back
#define all(v) v.begin(),v.end()
#define sort_1(v) sort(v.begin(),v.end())
#define sort_2(v) sort(v.begin(),v.end(),greater<ll>())
#define reverse(v) reverse(v.begin(),v.end())
typedef long long ll;
typedef long double la;
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    int ans = 1;
    rep(i,n){
        if(ans*2 < ans + k){
            ans = ans*2;
        }else{
            ans = ans + k;
        }
    }
    cout << ans << endl;
    return 0;
}
