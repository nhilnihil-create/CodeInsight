#include<cstdio>
#include<cstring>
#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<string>
#include<cmath>
#include<algorithm>
#include<complex>
#include<vector>
#include<set>
#include<map>
#include<queue>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define LL long long
#define FOR(i,a,b) for (int i=a;i<=b;++i)
#define FORD(i,a,b) for (int i=a;i>=b;--i)
using namespace std;
typedef pair<int,int> pa;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
int vs,k;
LL now,v[500010];
int S(LL x){
	int t=0;
	while (x) t+=x%10,x/=10;
	return t;
}
int main(){
	now=1e15;
	--now;
	v[vs=1]=now;
	while (now>1){
		LL t;
		if (now==1199){
			int tt=1;
		}
		for (t=1;t<now;t*=10){
			LL tmp=now-t;
			if (S(tmp)*now>=S(now)*tmp){//S(tmp)/tmp>=S(now)/now
				now=tmp;
				v[++vs]=now;
				break;
			}
		}
	}
	reverse(v+1,v+vs+1);
	cin>>k;
	FOR(i,1,k) cout<<v[i]<<endl;
	return 0;
}