#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e15;
#include "string"

int32_t main() {
	int t=1;
	//cin>>t;
	while(t--) {
		int n , k;
		cin >> n >> k;
		int a[n +1];
		a[0] = 0;
		for(int i =1; i <= n; i++) 
			cin>>a[i];
		int ans = 0;
		for(int i=1;i<=min(n,k);i++){
			vector<int>left;
			for(int l=0;l<=i;l++){
				if(l > 0)
					left.push_back(a[l]);
				vector<int>v = left;
				int c = i - l,r=n;
				while(c > 0){
					v.push_back(a[r]);
					c--;
					r--;
				}
				int rem = k - i,sum = 0;
				sort(v.begin(),v.end());
				for(int j=0;j<v.size();j++){
					if(v[j]<0 && rem>0)
						rem--;
					else
						sum += v[j];
				}
				ans = max(ans,sum);
			}
		}
		cout<<ans<<endl;
	}	
}