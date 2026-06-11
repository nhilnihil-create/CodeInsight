#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#include<stack>
#include<set>
#include<map>
#include<vector>
using namespace std;
string a="AKIHABARA";
string b;
int main(){
	cin>>b;
	int n=b.length();
	if(n>9){
		printf("NO");
		return 0;
	}
	int f=1,j=0;
	for(int i=0;i<n;i++){
		if(j>=9){
			f=0;
			break;
		}
		if(b[i]==a[j]){
			j++;
		}
		else if(a[j]=='A'){
			i--;
			j++;
		}
		else if(b[i]!=a[j]){
			f=0;
			break;
		}
	}
	if(j<8) f=0;
	if(f) printf("YES");
	else printf("NO");
	return 0;
}
