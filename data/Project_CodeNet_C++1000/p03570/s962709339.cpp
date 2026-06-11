#include<bits/stdc++.h>
const int N=2e5+9;
using namespace std;
map<int,int>tab;
vector<int>belong[N];
vector<int>g[N];
int num[N],w[N],tot,f[N];
char s[N];
int main()
{
	scanf("%s",s);
	int len=strlen(s);
    for(int i=len;i>=1;--i) s[i]=s[i-1];
//cout<<len<<"------"<<endl;
	for(int i=1;i<=len;++i)
	{
		num[s[i]-'a']++;
		for(int j=0;j<26;++j) if(num[j]%2) w[i]+=(1<<j);
	}
	w[0]=0;
	for(int i=len;i>=0;--i)
	{
	   if(tab.find(w[i])==tab.end())
	   {
	   	  tab[w[i]]=++tot;
	   	  belong[tot].push_back(i);
	   }
	   else belong[tab[w[i]]].push_back(i);
	   
	   int all=belong[tab[w[i]]].size();
	   int pos=tab[w[i]];
	   if(all>1) g[belong[pos][all-2]].push_back(i);
	   
	   int now=0;
	   for(int j=0;j<26;++j) 
	   {
		 if((1<<j)&w[i]) 
          {
          	int p;
          	if(tab.find(w[i]-(1<<j))==tab.end()) continue;
          	else p=tab[w[i]-(1<<j)];
		    int sz=belong[p].size();
		    if(sz) g[belong[p][sz-1]].push_back(i);
		  }
		 else 
		 {
		 	int p;
          	if(tab.find(w[i]+(1<<j))==tab.end()) continue;
          	else p=tab[w[i]+(1<<j)];
          	int sz=belong[p].size();
		    if(sz) g[belong[p][sz-1]].push_back(i);
		 }
	   }
	}
	for(int i=0;i<=len;++i) f[i]=len;
    f[0]=0;
	for(int i=1;i<=len;++i)
	{
		int sz=g[i].size();
		for(int j=0;j<sz;++j)
		 {
		  if(w[g[i][j]]!=w[i]) f[i]=min(f[i],f[g[i][j]]+1);
	      else
		   {
			 if(g[i][j]) f[i]=min(f[i],f[g[i][j]]);
	         else f[i]=min(f[i],1);
		   }
		 }
	}
	cout<<f[len]<<endl;
	return 0;
}
/*
abcabcxabcx
abaccbccaad
*/