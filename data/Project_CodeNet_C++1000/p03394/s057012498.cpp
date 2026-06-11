#include<bits/stdc++.h>
using namespace std;
int e[8]={2,10,3,9,4,8,6,12};
int o[8]={6,2,10,3,9,4,8,12};


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	if(n==3)	cout<<"2 5 63"<<endl;
	else{
		if(n&1){
			for(int i=0;i<n;i++)
				cout<<o[i&7]+(i>>3)*12<<' ';
		}
		else{
			for(int i=0;i<n;i++)
				cout<<e[i&7]+(i>>3)*12<<' ';
		}
	}
}
