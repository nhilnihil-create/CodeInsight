//Author: Fuadul Hasan(fuadul202@gmail.com)
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N   = 2e5 + 5;

int main(){
	
	int a[5];
	for(int i=0;i<5;i++){
		cin>>a[i];
	}	
	int dis;
	cin>>dis;

	sort(a,a+5);

	for(int i=0;i<5;i++){
		for(int j=i+1;j<5;j++){
			if(a[j]- a[i]>dis){
				cout<<":("<<endl;
				return 0;
			}
		}
	}


cout<<"Yay!"<<endl;

	

	return 0;
}