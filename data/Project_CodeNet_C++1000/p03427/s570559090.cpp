#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string str; 
  	cin>>str;

	int sum=0;
	for(char c:str) 
      sum+=c-'0';
	cout<<max<int>(sum,(str[0]-'1')+9*(str.length()-1))<<'\n';

	return 0;
}
