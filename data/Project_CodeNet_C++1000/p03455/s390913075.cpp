#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <iomanip>
using namespace std;

int main(){
	long long int a,b,c;
	string s="Odd";
	cin>>a>>b;
	c=(a*b)%2;
	if(c==0){
		s="Even";
	}
	cout<<s<<endl;
    return 0;
}