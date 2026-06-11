#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(x) (x).begin(),(x).end()

int main(){
	int a,b,c;
	vector<int> v(3);
	rep(i,3) cin>>v[i];
	sort(all(v));
	int r=v[2]-v[1];
	int l=(v[2]-v[0]-r);
	if(l%2==0) cout<<r+l/2<<endl;
	else cout<<r+l/2+2<<endl;
}