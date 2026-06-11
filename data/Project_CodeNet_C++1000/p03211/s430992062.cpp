#include<iostream>
#include<cstring>
#include<string>
using namespace std;
string s;
int a,p=753,i,x=9999;
int absx(int a){
	if(a<0)a*=-1;
	return a;
}
int minx(int a,int b){
	if(a<b)return a;
	return b;
}
int main(){
	cin>>s;
	for(i=0;i<s.length();i++){
		s[i]-=48;
	}
	for(i=2;i<s.length();i++){
		a=s[i-2]*100+s[i-1]*10+s[i];
		x=minx(x,absx(a-p));
	}
	cout<<x<<endl;
	return 0;
}