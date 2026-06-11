#include<bits/stdc++.h>
using namespace std;

int a,b;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>a>>b;
	if(a * b % 2 == 0){
		cout<<"Even"<<endl;
	}else{
		cout<<"Odd"<<endl;
	}
}
