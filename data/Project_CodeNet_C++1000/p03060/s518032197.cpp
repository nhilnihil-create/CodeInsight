#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,x=0,y=0;
		cin>>n;
		vector<int> v(n,0);
		vector<int> c(n,0);
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		for(int i=0;i<n;i++){
			cin>>c[i];
		}
		for(int i=0;i<n;i++){
			if(v[i]>=c[i]){
				x = x+v[i];
				y = y+c[i];
			}
		}
		cout<<x-y<<"\n";

	return 0;
}