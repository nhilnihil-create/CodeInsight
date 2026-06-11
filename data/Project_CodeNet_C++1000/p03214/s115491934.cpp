#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstdio>
#include<cmath>
#include<numeric>
#include<queue>
#include<stack>
#include<cstring>
#include<limits>
#include<functional>
#include<unordered_set>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define pb push_back
#define eb emplace_back
using ll=long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 50;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<double>a(n);
    double sum=0;
    rep(i,n){
        cin>>a[i];
        sum+=a[i];
    }
    sum/=n;
    int ans;
    double minv=1000;
    rep(i,n){
        if(chmin(minv,abs(sum-a[i]))){
            ans=i;
        }
    }
    cout<<ans<<"\n";
}

signed main(){
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	solve();
	return 0;
}
