#include <bits/stdc++.h>
using namespace std;

int n,h,w,a,b;
int brojac;

int main(){
	cin>>n>>h>>w;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		if(a>=h && b>=w)brojac++;		
	}
	
	cout<<brojac;
}