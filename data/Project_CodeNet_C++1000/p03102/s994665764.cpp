#include <bits/stdc++.h> 
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<vector<int>>;

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}

const double PI=(acos(-1));

int main(){
    int n,m,c;
    cin>>n>>m>>c;
    c=-c;
    vector<int> b(m);
    rep(i,m)cin>>b[i];
    vector<vector<int>> a(n,vector<int>(m));
    vector<int> d(n);
    rep(i,n){
        rep(j,m){
            cin>>a[i][j];
            d[i]+=a[i][j]*b[j];
        }
    }
    int ans=0;
    rep(i,n){
        if(d[i]>c)++ans;
    }
    cout<<ans<<endl;
}