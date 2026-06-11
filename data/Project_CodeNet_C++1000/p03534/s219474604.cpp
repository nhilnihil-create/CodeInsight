#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5,inf=0x3f3f3f3f;
string s;
int cnt[3]={0};
int main()
{
	cin>>s;
	for(int i=0;s[i];i++)
		cnt[s[i]-'a']++;
	sort(cnt,cnt+3);
	cnt[1]-=cnt[0];
	cnt[2]-=cnt[0];
	bool flag=true;
	if(cnt[1]>1||cnt[2]>1)
		flag=false;
	puts(flag?"YES":"NO");
    return 0;
}


