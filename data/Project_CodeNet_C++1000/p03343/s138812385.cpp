#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,k,q; cin >> n >> k >> q;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	n++;
	a.push_back(-1);
	
	int ans=INT_MAX;
	for(int i=0;i<n-1;i++){
		vector<int> tot,la;
		for(int j=0;j<n;j++){			
			if(a[j]<a[i]){
				sort(la.begin(),la.end());
				for(int r=0;r<int(la.size())-k+1;r++){
					tot.push_back(la[r]);
				}
				la.clear();
			}
			else{
				la.push_back(a[j]);
			}
		}
		sort(tot.begin(),tot.end());
		if(tot.size()>=q)
			ans=min(ans,tot[q-1]-tot[0]);
	}
	
	cout << ans << endl;
	return 0;
}