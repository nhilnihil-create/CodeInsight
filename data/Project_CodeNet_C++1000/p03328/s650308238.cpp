#include<iostream>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
using namespace std;

int main(){
	int a,b;
	cin>>a>>b;
	cout<<0.5*(1+(b-a))*(b-a)-b<<endl;
	return 0;
}