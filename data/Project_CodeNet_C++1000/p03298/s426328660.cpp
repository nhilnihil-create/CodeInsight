#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=40;
int n,S;
char str[N];
ll sum;
map<pair<string,string>,int>dd;
int main(){
	int i;
	scanf("%d",&n);
	scanf("%s",str+1);
	for(S=0;S<1<<n;S++){
		string R="",B="";
		for(i=0;i<n;i++)((S>>i&1)?R:B)+=str[i+1];
		++dd[make_pair(R,B)];
	}
	for(S=0;S<1<<n;S++){
		string R="",B="";
		for(i=0;i<n;i++)((S>>i&1)?R:B)+=str[2*n-i];
		sum+=dd[make_pair(R,B)];
	}
	printf("%lld\n",sum);
}