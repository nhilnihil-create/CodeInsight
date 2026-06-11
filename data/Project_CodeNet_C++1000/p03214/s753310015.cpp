#include<bits/stdc++.h>
using namespace std;
int ar[105];
int main(){
	int sum=0;int n;cin>>n;
  	for(int i=1;i<=n;i++){cin>>ar[i];sum+=ar[i];ar[i]*=n;}
  	int mn=abs(sum-ar[1]),mni=1;
  	for(int i=2;i<=n;i++){
    	if(abs(sum-ar[i])<mn){
        	mn = abs(sum-ar[i]);mni=i;
        }
    }
  	cout<<mni-1;
}