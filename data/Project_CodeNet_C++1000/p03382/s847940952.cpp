#include<bits/stdc++.h>
using namespace std;

int data[100005];

int main(){
	int ban;
	scanf("%d",&ban);
	int mx=0;
	for(int i=0;i<ban;i++){
		scanf("%d",&data[i]);
		if(mx<data[i])mx=data[i];
	}
	int med1=ceil(mx/2),med2=mx/2;
	int sel=1000000000,mn;
	for(int i=0;i<ban;i++){
		if(abs(med1-data[i])<sel && data[i]!=mx){
			sel=abs(med1-data[i]);
			mn=data[i];
		}
		if(abs(med2-data[i])<sel && data[i]!=mx){
			sel=abs(med2-data[i]);
			mn=data[i];
		}
	}
	printf("%d %d\n",mx,mn);
	return 0;
}