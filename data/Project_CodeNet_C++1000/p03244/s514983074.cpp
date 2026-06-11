#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<locale.h>
#include<set>
#include<stack>
#include<queue>
#include<math.h>
using namespace std;
typedef long long int ll;
int main()
{
 int n;
 pair<int,int>k[100001];
 pair<int,int>g[100001];
 scanf("%d",&n);
 for(int i=0;i<=100000;i++)
 {
	k[i].first=g[i].first=0;
	k[i].second=g[i].second=i;
 }
 for(int i=1;i<=n;i++)
 {
	int a;
	scanf("%d",&a);
	if(i%2==1){k[a].first++;}
	if(i%2==0){g[a].first++;}
 }

 sort(k,k+100001,greater<>());
 sort(g,g+100001,greater<>());
 int ans=0;
 if(k[0].second!=g[0].second){ans=k[0].first+g[0].first;}
 else{ans=max(k[0].first+g[1].first,k[1].first+g[0].first);}
 ans=n-ans;
 printf("%d",ans);

} 