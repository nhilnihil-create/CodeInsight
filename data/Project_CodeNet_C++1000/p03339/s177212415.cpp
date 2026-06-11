#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 1

int main()
{	
	ios_base::sync_with_stdio(0);
	string str;
	int len;
	while(cin>>len>>str){
		vector<int> east(len+2,0), west(len+2,0);
		for(int i=0; i<len; i++){
			west[i+1] = west[i] + (str[i]=='W');
		}
		for(int i=len-1; i>=0; i--){
			east[i+1] = east[i+2] + (str[i]=='E');
		}
		int ans = len;
		for(int i=1; i<=len; i++){
			ans = min(ans, west[i-1] + east[i+1]);
		}
		cout<<ans<<endl;
	}
}

