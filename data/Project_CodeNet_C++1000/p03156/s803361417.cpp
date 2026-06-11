#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,a,b,c=0,d=0,e=0,p;
	cin>>n>>a>>b;
	for(int i=0;i<n;i++){
		cin>>p;
		if(p<=a){
			c++;
		}else if(p>=a+1 && p<=b){
			d++;
		}else if(p>=b+1){
			e++;
		}
	}
	cout<<min({c,d,e})<<endl;
	return 0;
}
