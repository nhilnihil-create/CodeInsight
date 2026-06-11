#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;
typedef long long ll;

char a[100000+5];

int main()
{
	scanf("%s",a);
	int len=strlen(a);
	int ans=0x7fffffff;
	for(int i=0;i<len-1;i++){
		if(a[i]!=a[i+1]){
			ans=min(ans,max(i+1,len-i-1));
		}
	}
	if(ans==0x7fffffff){
		cout<<len<<endl;
	}
	else {
		cout<<ans<<endl;
	}
	return 0;
}	 
