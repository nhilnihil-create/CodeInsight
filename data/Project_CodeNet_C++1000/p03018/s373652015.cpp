#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()


int main() {
    string s;
    cin>>s;

    int n=s.size();
    string t="";
    int i=0;
    for(i=0;i<n-1;i++){
        if(s[i]=='B' && s[i+1]=='C'){
            t+='X';
            i++;
        }
        else t+=s[i];
    }
    if(i==n-1) t+=s[i];

    ll ans=0,cnt=0;
    rep(i,t.size()){
        if(t[i]=='A') cnt++;
        else if(t[i]=='X') ans+=cnt;
        else cnt=0;
    }

    cout<<ans<<endl;
}