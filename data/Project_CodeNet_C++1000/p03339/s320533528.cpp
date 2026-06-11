#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
using ll = long long;
typedef pair<int, int> P;

int main(){
    int n,e=0,w=0;
    string s;
    cin>>n>>s;
    rep(i,n){
        e+=s[i]=='E';
        w+=s[i]=='W';
    }
    int ans=INT_MAX,now=e;//now=変えるべき人数
    rep(i,n){
        if(s[i]=='E'){
            ans=min(ans,now-1);
            now--;
        }
        else{
            ans=min(ans,now);
            now++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
