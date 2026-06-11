#include<bits/stdc++.h>
using namespace std;
int ar[105];
int cur=10000;
int main(){
  	int n;cin>>n;for(int i=1;i<=n;i++)cin>>ar[i];int ans=0;
  	for(int i=1;i<=n;i++){
    	if(ar[i+1]==ar[i]){
        	ar[i+1]=cur--;ans++;
        }
    }
  	cout<<ans;
}