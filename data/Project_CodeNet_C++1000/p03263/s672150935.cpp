#include <bits/stdc++.h>
#define rep(a,n) for (int a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> PP;
typedef vector<vector<int> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = 1e9;



int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<int> >a(h,vector<int>(w));
    rep(i,h)rep(j,w)cin>>a[i][j];
    vector<pair<P,P> >sousa;
    rep(i,h-1){
        rep(j,w){
            if(a[i][j]%2==0)continue;
            a[i+1][j]+=a[i][j];
            sousa.push_back({{i+1,j+1},{i+2,j+1}});
        }
    }
    rep(j,w-1){
        if(a[h-1][j]%2==0)continue;
        a[h-1][j+1]+=a[h-1][j];
        sousa.push_back({{h,j+1},{h,j+2}});
    }
    int n = sousa.size();
    cout << n << endl;
    rep(i,n){
        int X1,X2,Y2,Y1;
        Y1 = sousa[i].first.first;
        X1 = sousa[i].first.second;
        Y2 = sousa[i].second.first;
        X2 = sousa[i].second.second;
        printf("%d %d %d %d\n",Y1,X1,Y2,X2);
    }
    return 0;
}
