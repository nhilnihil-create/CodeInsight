#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int a, b;
	cin>>a>>b;
	int c1=0;
	int c2=0;
	int c3=0;
	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		if(x<=a){
			c1++;
		}
		else if(x>=b+1){
			c3++;
		}
		else{
			c2++;
		}
	}
	int mini1=min(c1, c2);
	mini1=min(mini1, c3);
	cout<<mini1;
	return 0;
}