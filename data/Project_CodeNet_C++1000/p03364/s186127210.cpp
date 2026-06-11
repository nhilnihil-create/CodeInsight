#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    int n;
    cin>>n;
    vector<string>s(n);
    rep(i,n)cin>>s[i];
    int ans=0;
    rep(dy,n){
        bool ng=false;
        rep(i,n)rep(j,n){
            if(s[(dy+i)%n][j]!=s[(dy+j)%n][i])ng=true;
        }
        if(!ng)ans+=n;
    }
    cout<<ans<<endl;
}