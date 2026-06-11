#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double D;
typedef pair<int,int> P;
#define M 1000000007
#define M2 100000007
#define F first
#define S second
#define PB push_back
#define INFL 1000000000000000000
#define INF 1000000000
string s;
bool v[500];
int main(void){
	cin>>s;
	int n=s.size();
	for(int i=n;i>=0;i--){
		char p;
		if(i==n)p='a'-1;
		else p=s[i];
		for(int j='a';j<='z';j++)v[j]=false;
		for(int j=0;j<i;j++)v[s[j]]=true;
		for(int j=p+1;j<='z';j++){
			if(v[j]==false){
				for(int k=0;k<i;k++)printf("%c",s[k]);
				printf("%c\n",j);
				return 0;
			}
		}
	}
	printf("-1\n");
}