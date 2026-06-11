#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
using Graph = vector<vector<int>>;
int main(int argc, const char * argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    char c[3][2];
    rep(i,2){
        rep(j,3){
            cin>>c[j][i];
        }
    }
    bool flag=true;
    rep(i,2){
        rep(j,3){
            if(c[j][i]!=c[2-j][1-i])flag=false;
        }
    }
    if(flag)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}
