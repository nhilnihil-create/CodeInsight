#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1e6;
string s[maxn];
int main(){
	int n,A=0,B=0,AB=0,sum=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i];
		int len=s[i].size()-1;
		for(int j=1;j<=len;j++){
			if(s[i][j]=='B'&&s[i][j-1]=='A') sum++;
		}
		if(s[i][0]=='B'&&s[i][len]=='A'){
			AB++;continue;
		}
		if(s[i][0]=='B'){
			B++;continue;
		}
		if(s[i][len]=='A'){
			A++;continue;
		}
	}
	int ans=0;
	if(AB>0){
		if(A>0||B>0){
			A--; B--;
			ans+=2;AB--;			
		}
		else AB--;
	}
	ans+=min(A,B)+AB+sum;
	cout<<ans<<endl;
	return 0;
}