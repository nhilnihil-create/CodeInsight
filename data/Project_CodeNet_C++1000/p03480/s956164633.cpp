#include<bits/stdc++.h>
using namespace std;
char c[100100];
int main()
{
	scanf("%s",c+1);
	int len=strlen(c+1);
	if(len%2==0){
		int ans=len/2;
		int mid=len/2;
		int l=mid;
		int r=mid+1;
		while(c[l]==c[r]&&c[l]==c[mid]&&l>=1&&r<=len){
			ans++;
			l--;
			r++;
		}
		cout<<ans<<endl;
	}
	else{
		int ans=len/2;
		int mid=len/2+1;
		int l=mid;
		int r=mid;
		while(c[l]==c[r]&&c[l]==c[mid]&&l>=1&&r<=len){
			ans++;
			l--;
			r++;
		}
		cout<<ans<<endl;
	}
	return 0;
}