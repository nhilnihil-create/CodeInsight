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

int main(){
    int n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n)cin>>a[i];
    vector<ll> l(n+1),r(n+1);
    l[0]=a[0];
    r[0]=a[n-1];
    rep(i,n){
        l[i+1]=__gcd(l[i],a[i+1]);
        r[i+1]=__gcd(r[i],a[(n-1)-(i+1)]);
    }
    vector<ll> ans(n);
    ans[0]=r[n-2];
    ans[n-1]=l[n-2];
    for(int i=1;i<n-1;++i){
        ans[i]=__gcd(l[i-1],r[n-3-(i-1)]);
    }
    ll ret=0;
    rep(i,n){
        ret=max(ret,ans[i]);
    }
    cout<<ret<<endl;
}


