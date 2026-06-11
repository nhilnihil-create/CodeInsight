#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
using Graph = vector<vector<int>>;
int main(int argc, const char * argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    char c[3][3];
    rep(i,3){
        rep(j,3){
            cin>>c[i][j];
        }
    }
    rep(i,3)cout<<c[i][i];
    cout<<endl;

    return 0;
}