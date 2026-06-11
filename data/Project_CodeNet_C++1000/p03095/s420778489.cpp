#include <bits/stdc++.h>
using namespace std;

int main(){
  map<char,int>mp;
  char c;
  int n;
  long long sum;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>c;
		mp[c]++; 
	}
	sum=1;
	for(char i='a';i<='z';++i){
		sum*=(mp[i]+1);
		sum%=1000000007;
	}
	cout<<sum-1<<endl;
}