#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
typedef long long ll;
const int N=40;
int n;
char s[N];
ll ans;
map<pair<string,string>,int>Map;
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	for (int S=0;S<1<<n;S++){
		string R="",B="";
		for (int i=0;i<n;i++)
			if (S&(1<<i))R+=s[i+1];
			else B+=s[i+1];
		Map[mp(R,B)]++;
	}
	for (int S=0;S<1<<n;S++){
		string R="",B="";
		for (int i=0;i<n;i++)
			if (S&(1<<i))R+=s[2*n-i];
			else B+=s[2*n-i];
		ans+=Map[mp(R,B)];
	}
	printf("%lld\n",ans);
}
