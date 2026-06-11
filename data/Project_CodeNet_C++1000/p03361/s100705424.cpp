#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<char>> s(h,vector<char>(w));
    rep(i,h)rep(j,w) cin >> s[i][j];
    vector<vector<bool>> check(h,vector<bool>(w,false));
    rep(i,h){
        rep(j,w){
            int dx[4]={1,0,-1,0};
            int dy[4]={0,1,0,-1};
            rep(k,4){
                if(i==0 && k==3) continue;
                if(i==h-1 && k==1) continue;
                if(j==0 && k==2) continue;
                if(j==w-1 && k==0) continue;
                if(s[i+dy[k]][j+dx[k]] == '#') check[i][j]=true;
            }
        }
    }
    rep(i,h)rep(j,w) if(s[i][j]=='#' && check[i][j]==false){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}