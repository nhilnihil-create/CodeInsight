#include <bits/stdc++.h>
using namespace std;
int main() {
	int l=0,s=0,n;
	for(int i=0;i<5;i++){
		cin>>n; s+=(n+9)/10*10; l=max(l,(10-n%10)%10);
	}
	cout<<s-l;
}