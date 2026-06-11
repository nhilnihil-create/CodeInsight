#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	int s,s1,s2;
	s=a+b;
	s1=a-b;
	s2=a*b;
	cout<<max(max(s,s1),s2)<<endl;
}