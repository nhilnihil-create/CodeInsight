#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define pb push_back
#define mp make_pair
#define endl "\n"
#define ff first
#define ss second
 
#ifndef ONLINE_JUDGE
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){cerr << name << " : " << arg1 << endl;}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');
	cerr.write(names, comma - names) << " : " << arg1 << "  ";
	__f(comma + 1, args...);}
#else
#define debug(...)
#endif
 
const int inf = 2e18;
const int mod = 1e9 + 7;

signed main(){
 
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		freopen("error.txt","w",stderr);
	#endif
 
	int n, k; cin>>n>>k;
	vector<int> arr(n);
	vector<int> ans(k+1);
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	for(int i=0; i<=k; i++){
		bool flag = true;
		for(int j=0; j<n; j++){
			if(i-arr[j]>=0){
				if(ans[i-arr[j]]==2){
					ans[i] = 1;
					flag = false;
					break;
				}
			}
		if(flag) ans[i] = 2;
		}
	}
	if(ans[k]==1) cout<<"First"<<endl;
	else cout<<"Second"<<endl;
	return 0;
}