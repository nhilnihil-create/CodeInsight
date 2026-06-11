#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define rer(i, a, b) for(int i = int(a) - 1; i >= int(b); i--)
#define sz(v) (int)(v).size()
#define pb push_back
#define sc second
#define fr first
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
using namespace std;
typedef long long int ll;
typedef pair <string, string> P;

const ll MOD=1000000007;
map<P,ll> m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin>>N;
    string s;
    cin>>s;
    rep(i,0,1<<N){
        string c;
        string d;
        rep(j,0,N){
            if(i&(1<<j)){
                c+=s[j];
            }
            else d+=s[j];
        }
        m[P(c,d)]++;
    }
    ll ans=0;
    rep(i,0,1<<N){
        string c;
        string d;
        rep(j,0,N){
            if(i&(1<<j)){
                c+=s[2*N-1-j];
            }
            else d+=s[2*N-1-j];
        }
        ans+=m[P(c,d)];
    }
    cout <<ans<<"\n";
}