#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char ca[100007];
int main(){
	int n[3]={0};
	int i,j,k;
	cin>>ca;
	for(i=0;i<strlen(ca);i++){
		j=(int)ca[i]-(int)'a';
		n[j]++;
	}
	if(n[0]>n[1])swap(n[0],n[1]);
	if(n[1]>n[2])swap(n[1],n[2]);
	if(n[0]>n[1])swap(n[0],n[1]);
	if(n[2]-n[0]<=1)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
