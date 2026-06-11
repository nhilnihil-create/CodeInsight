  /*  HARD WORK FOREVER PAYS  */
#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define turbo(){	\
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL); \
}
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
int main()
{
	turbo();
	string s;
	cin>>s;
	ll cnt=0,sz=s.size(),j=0,i;
	for(i=0;i<sz;i++){
		if(s[i]=='B') j++;
		else cnt+=j;
	}
	cout<<cnt<<endl;
	return 0;
}