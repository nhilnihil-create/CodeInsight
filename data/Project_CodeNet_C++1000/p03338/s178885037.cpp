#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());

int main(){
	int n; cin>>n;
	string s; cin>>s;
	int mx=0;
	rep(i,n-1){
		int cnt=0;
		vector<char> a;
		for(int k=0; k<=i; k++){
			a.push_back(s[k]);
		}
		sort(all(a));
		UNIQUE(a);
		
		vector<char> b;
		for(int j=i+1; j<n; j++){
			b.push_back(s[j]);
		}
		sort(all(b));
		UNIQUE(b);
		for(auto x:a){
			for(auto y:b){
				if(x==y) cnt++;
			}
			mx=max(mx,cnt);
		}
	}
	cout<<mx<<endl;
}