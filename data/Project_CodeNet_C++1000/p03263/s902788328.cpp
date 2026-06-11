#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;



int main(){
    
    int H, W;
    cin>>H>>W;
    vector<vector<int>> a(H, vector<int>(W));
    int odd=0;
    rep(i,H){
        rep(j,W) {
            cin>>a[i][j];
            if(a[i][j] & 1) odd++;
        }
    }

    vector<pair<P, P>> res;
    int num = 0;
    int x = 0, y = 0;
    rep(i, W*H){
        if(a[x][y] & 1) num++;

        int nx = x, ny = y;
        if(x%2 == 0){
            if(ny == W-1) nx++;
            else ny++;
        }else{
            if(ny == 0) nx++;
            else ny--;
        }
        if(num & 1){
            if(num < odd) res.push_back(make_pair(make_pair(x, y), make_pair(nx, ny)));
        }
        x = nx;
        y = ny;
    }
    cout<<res.size()<<endl;
    for(auto p: res){
        cout<<p.first.first+1<<" "<<p.first.second+1<<" "<<p.second.first+1<<" "<<p.second.second+1<<endl;
    }
}
