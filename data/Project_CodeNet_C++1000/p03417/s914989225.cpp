#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <iomanip>
using namespace std;

int main(){
	long long int a,b;
	cin>>a>>b;
	if(a==1&&b==1){
		cout<<1<<endl;
	}
	else if(a==1){
		cout<<b-2<<endl;
	}
	else if(b==1){
		cout<<a-2<<endl;
	}
	else{
		cout<<(a-2)*(b-2)<<endl;
	}
	
	return 0;
}