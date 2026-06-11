#include<iostream>
#include<algorithm>
using namespace std;
main(){
	int n,h,w;
	cin>>n>>h>>w;
	int ai[1050],bi[1050];
	int c=0,d;
 for(int i=0;i<n;i++){
     	cin>>ai[i];
     	cin>>bi[i];
	 }
	for(int i=0;i<n;i++){
		if(ai[i]>h||ai[i]==h)if(bi[i]>w||bi[i]==w)c++;
	}
	cout<<c;
} 