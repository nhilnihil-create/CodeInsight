#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod =1e+9+7;

const int dy[8]={1,1,1,0,-1,-1,-1,0};
const int dx[8]={1,0,-1,-1,-1,0,1,1};
int main(){
    ll h,w; cin>>h>>w;
    vector<vector<char>>a(h,vector<char>(w));
    rep(i,h){
        rep(j,w)cin>>a[i][j];
    }
    rep(i,h){
        rep(j,w){
            if(a[i][j]=='#')continue;
            ll cnt=0;
            rep(k,8){
                if(i+dy[k]<0||i+dy[k]>=h)continue;
                else if(j+dx[k]<0||j+dx[k]>=w)continue;
                if(a[i+dy[k]][j+dx[k]]=='#')cnt++;
            }
            char c='0'+cnt;
            a[i][j]=c;
        }
    }
    rep(i,h){
        rep(j,w){
            cout<<a[i][j];
        }
        cout<<endl;
    }
}
























































































