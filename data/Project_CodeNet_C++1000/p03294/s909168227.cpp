#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    int t = 1; //cin >> t;
    while(t--){
    	int n; cin >> n;
    	vector<int> a(n);
    	int ans = 0, f = 0;
    	for (int i = 0; i < n; ++i)
    	{
    		cin >> a[i];
    		f += a[i] - 1;
    	}
    	cout << max(ans,f);
    }    
}