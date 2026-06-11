#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin, (x).rend()
#define endl '\n'
#define F first
#define S second
typedef pair<int,int> pii;
typedef long long ll;

int main(){
	int n,m,ans=0; cin>>n>>m;
	vector<int> B[m];
	int arr[m];
	for(int i=0; i<m; i++){
		int t; cin>>t;
		for(int j=0; j<t; j++){
			int x; cin>>x;
			B[i].push_back(x);
		}
	}
	for(int i=0; i<m; i++){
		cin>>arr[i];
	}
	for(int mask=0; mask<(1<<n); mask++){
		bool pass=true;
		for(int i=0; i<m; i++){
			int cnt=0;
			for(auto x: B[i]){
				x--;
				if((mask>>x) & 1)cnt++;
			}
			if(cnt%2 != arr[i])pass=0;
		}
		if(pass)ans++;
	}
	cout<<ans<<endl;
}
