#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;
#define all(x) (x).begin(),(x).end()

int main(){
	int n,x; cin>>n;
	n++;
	vector<int> v(n);
	rep(i,n) cin>>v[i];
	sort(all(v));
	n--;
	vector<int> d(n);
	rep(i,n) d[i]=v[i+1]-v[i];
	sort(all(d));
	for(int i=d[0]; i>0; i--){
		bool flg=true;
		for(int j=1; j<n; j++){
			if(d[j]%i!=0) {flg=false; break;}
		}
		if(flg) {cout<<i<<endl; return 0;}
	}
}