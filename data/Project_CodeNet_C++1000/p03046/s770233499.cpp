#include<bits/stdc++.h>
using namespace std;
int main() {
	int m, k;
	cin>>m>>k;
	if((m==0||m==1)&&(k>0)) {
		cout<<-1;
		return 0;
	}
	if(k>(1<<m)-1) {
		cout<<-1;
		return 0;
	}
	if(m==1) {
		cout<<"0 1 1 0";
		return 0;
	}
	for(int i=0;i<=(1<<m)-1;i++) {
		if(i!=k) printf("%d ", i);
	}
	cout<<k<<" ";
	for(int i=(1<<m)-1;i>=0;i--) {
		if(i!=k) printf("%d ", i);
	}
	cout<<k<<" ";
}