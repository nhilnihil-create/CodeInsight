#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <bitset> 
#include <cstdio> 
#include <vector>
using namespace std;
int n;
char str[100010];
int main(){
	cin>>str;
	int L=strlen(str);
	int middle=L/2;
	int ans=middle;
	char mch=str[middle];
	if(L&1){
		for(int i=middle;i>=0;i--){
			if(str[i]==mch&&str[L-1-i]==mch){
				ans++;
			}
			else break;
		}
	}
	else {
		middle--;
		for(int i=middle;i>=0;i--){
			if(str[i]==mch&&str[L-1-i]==mch){
				ans++;
			}
			else break;
		}
	}
	cout<<ans;
	return 0;
}
