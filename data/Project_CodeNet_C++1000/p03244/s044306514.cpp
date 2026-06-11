#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int i,j,k;
int n;
int a[maxn],ha[maxn],t1,t2,t3,t4,t5,t6;
int main(){
	cin>>n;
	for (i=1;i<=n;i++){
		cin>>a[i];
	}
	t1=n; t3=n; t2=n; t4=n;
	for (i=2;i<=n;i=i+2){
		ha[a[i]]++;
	}
	for (i=0;i<maxn;i++){
		t1=min(t1,(n/2)-ha[i]);
		if (t3>t1){
			swap(t3,t1);
			t5=i;
		}
	}
	memset(ha,0,sizeof(ha));
	for (i=1;i<=n;i=i+2){
		ha[a[i]]++;
	}
	for (i=0;i<maxn;i++){
		t2=min(t2,(n/2)-ha[i]);
		if (t4>t2){
			swap(t4,t2);
			t6=i;
		}
	}
	if (t5!=t6) printf("%d\n",t3+t4);
	else{
		printf("%d\n",min(t1+t4,t3+t2));
	}
	return 0;
}