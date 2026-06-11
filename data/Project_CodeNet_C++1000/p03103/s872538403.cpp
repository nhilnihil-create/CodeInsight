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
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>> ab(n);
    rep(i,n)cin>>ab[i].first>>ab[i].second;
    sort(ab.begin(),ab.end());
    ll ans=0;
    rep(i,n){
        if(m>=ab[i].second){
            ans+=ab[i].second*ab[i].first;
            m=m-ab[i].second;
        }else{
            ans+=m*ab[i].first;
            m=0;
        }
    }
    cout<<ans<<endl;
    return 0;
}