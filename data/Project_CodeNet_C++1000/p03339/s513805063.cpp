#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long int ll;
typedef unsigned long long ull;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
typedef pair<ll,ll> P;


int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int w=0,e=0;
    rep(i,n){
        if(s[i]=='W')w++;
        else e++;
    }
    
    int ans = n,aw=0,ae=0;
    rep(i,n){
        if(s[i]=='W'){
            w--;
            ans = min(ans,e+aw);
            aw++;
        }else{
            e--;
            ans = min(ans,e+aw);
            ae++;
        }
        //cout <<w<<" "<<aw<<" "<<e<<" "<<ae<<endl;       
    }
    cout << ans;
    return 0;
}