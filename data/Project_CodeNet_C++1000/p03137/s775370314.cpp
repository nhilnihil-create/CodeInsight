#include <bits/stdc++.h> 
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
#define MAX 100005
#define NIL -1
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<vector<int>>;

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}

const double PI=(acos(-1));

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> x(m);
    rep(i,m)cin>>x[i];
    vector<int> diff(m-1);
    if(n>=m){
        cout<<0<<endl;
        return 0;
    }else{
        sort(x.begin(),x.end());
        rep(i,m-1){
            diff[i]=x[i+1]-x[i];
        }
        sort(diff.begin(),diff.end());
        int ans=x[m-1]-x[0];
        rep(i,n-1){
            //cout<<diff[m-2-i]<<" ";
            ans-=diff[m-2-i];
        }
        cout<<ans<<endl;
        return 0;
    }
}
