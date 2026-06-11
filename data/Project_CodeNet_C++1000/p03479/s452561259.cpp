#include <bits/stdc++.h>
using namespace std;

long long x, y, tmp=1, arr[60], ans=1;

int main () {
	ios_base::sync_with_stdio(false);
	cin>>x>>y;
	
	for(long long i=0; true; i++){
		if(x>y){
			cout<<i<<endl;
			break;
		}
		else x*=2;
	}
}