#include<bits/stdc++.h>

using namespace std;
#define int long long
#define N 666666
int sum[N];
char str[N];
signed main(){
	
	cin>>(str+1);
	int add=0;
	int ans=0;
	int len=strlen(str+1);
	for(int i=1;i<=len;i++){
		if(str[i]=='A'){
			sum[i]=sum[i-1]+1;	
		}else if(str[i]=='C'){
			add=0;
	//		sum[i]=sum[i-1];
		}else{
			if(i-1>=1&&i+1<=len){
				if(str[i-1]=='A'&&str[i]=='B'&&str[i+1]=='C'){
					//cout<<sum[i-1]<<" ";
					ans+=sum[i-1];
					sum[i+1]+=sum[i-1];
					str[i+1]='A';
					i=i+1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}