#include<cstdio>
#include<algorithm>
#include<map>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
typedef long long LL;

map<pair <string,string>,LL> cnt;
const int maxn = 50;
char s[maxn];

int main()
{
    int n; scanf("%d",&n);
    scanf("%s",s);
    for(int i = 0;i < (1 << n);i++)
	{ 
        string s1 = "",s2 = "";
        for(int j = 0;j < n;j++)
		{
            if(i & (1 << j)) s1 += s[j]; 
            else s2 += s[j];
        }
        cnt[make_pair(s1,s2)]++; 
    }
    LL sum = 0;
    for(int i = 0;i < (1 << n);i++)
	{ 
        string s1 = "",s2 = "";
        for(int j = n - 1;j >= 0;j--)
		{
            if(i & (1 << j)) s2 += s[j + n]; 
            else s1 += s[j + n]; 
        }
        sum += cnt[make_pair(s1,s2)]; 
    }
    printf("%lld\n",sum);
}