#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main(){
		int n,k;scanf("%d %d",&n,&k);
		string str;cin>>str;
		str[k-1] = str[k-1]+32;
		cout<<str;	
		return 0;	
	}
