#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
string s;
int main()
{
	int a[3];
	while(cin>>s){
		int len=s.length();
		a[0]=a[1]=a[2]=0;
		for(int i=0;i<len;i++){
			if(s[i]=='a')
				a[0]++;
			else if(s[i]=='b')
				a[1]++;
			else 
				a[2]++;
		}
		sort(a,a+3);
		//cout<<a[0]<<a[1]<<a[2];
		if(a[2]-a[1]<=1&&a[1]-a[0]<=1&&a[2]-a[0]<=1)
			puts("YES");
		else
			puts("NO");
	}
}
