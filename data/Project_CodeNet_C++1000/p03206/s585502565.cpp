#include<bits/stdc++.h>
using namespace std;

int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	if(n == 25){
		cout<<"Christmas"<<endl;
	}else if(n == 24){
		cout<<"Christmas Eve"<<endl;
	}else if(n == 23){
		cout<<"Christmas Eve Eve"<<endl;
	}else{
		cout<<"Christmas Eve Eve Eve"<<endl;
	}
}
