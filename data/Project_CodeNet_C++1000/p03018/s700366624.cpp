#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 1e9
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    string s;
    cin>>s;
    string t;
    s+="#";
    rep(i,s.size()){
        if(s[i]=='B'&&s[i+1]=='C'){
            t+='X';
            i++;
        }
        else t+=s[i];
    }

    ll ans=0,cnt=0;
    rep(i,t.size()){
        if(t[i]=='A') cnt++;
        else if(t[i]=='X') ans+=cnt;
        else cnt=0;
    }

    cout<<ans<<endl;
}