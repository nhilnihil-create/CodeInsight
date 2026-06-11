#include<iostream>
#include<set>
using namespace std;
string s;
int i,k;
int main(){
	cin>>s>>k;
	set<string>m;
	for(;i<s.size();i++)for(int j=1;j<=k;j++)m.insert(s.substr(i,min(j,(int)s.size()-i)));
	auto itr=m.begin();while(--k)itr++;
	cout<<*itr<<endl;
	return 0;
}