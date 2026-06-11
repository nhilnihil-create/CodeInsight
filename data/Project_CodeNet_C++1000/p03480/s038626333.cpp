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
static const ll mod = 1e9 + 7;
static const ll INF = 1LL << 50;
using namespace std;

#define mega 300005

signed main(){
	string s;
	cin>>s;
	int maxv,min_maxv=mega;
	int n=(int)s.size();
	rep(i,n-1){
		if(s[i]!=s[i+1]){
			maxv=max(i+1,n-(i+1));
			min_maxv=min(maxv,min_maxv);
		}
	}
	if(min_maxv==mega)min_maxv=n;
	cout<<min_maxv<<endl;
	return 0;
}
