#include <bits/stdc++.h> 
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<vector<int>>;

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}

const double PI=(acos(-1));

ll mygcd(ll a,ll b){
    while(0<b){
        ll r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main(){
    int n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n)cin>>a[i];
    ll ans=10000000000;
    rep(i,n-1){
        ans=min(ans,mygcd(a[i],a[i+1]));
    }
    cout<<ans<<endl;

}