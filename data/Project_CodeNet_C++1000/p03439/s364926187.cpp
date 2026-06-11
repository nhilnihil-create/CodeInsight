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

template<typename T>void chmax(T &a,T b){a=max(a,b);}
template<typename T>void chmin(T &a,T b){a=min(a,b);}
using namespace std;

void solve(){
	int n;
	cin>>n;
	int left=0,right=n+1,mid=(left+right)/2;
	vector<string>s(20);
	rep(i,20){
		if(!i)cout<<0<<endl;
		else cout<<mid<<endl;
		cin>>s[i];
		if(s[i]=="Vacant")return;
		if(!i)continue;
		if(mid%2==0){
			if(s[0]!=s[i])right=mid;
			else left=mid;
		}
		else {
			if(s[0]!=s[i])left=mid;
			else right=mid;
		}
		mid=(left+right)/2;
	}
}

signed main(){
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	solve();
	return 0;
}
