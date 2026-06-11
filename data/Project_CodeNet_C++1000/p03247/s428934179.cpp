#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
#define INF 1e18
#define MOD 1000000007
#define N 1000005
#define BB(V) V[V.size()-2]
#define ex(V) return printf(V),0
using namespace std;
pii a[1005];
vector<int>d;
char dir[5]="LUDR";
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
		int t1,t2;
		scanf("%d%d",&t1,&t2);
		a[i]={t1+t2,t1-t2};
		if(!!(a[0].F%2)!=!!(a[i].F%2))ex("-1");
    }
    for(int i=30;i>=0;i--)d.push_back(1<<i);
    if(a[0].F%2==0)d.push_back(1);
    printf("%u\n",d.size());
    for(auto &p:d)printf("%d ",p);
    puts("");
    for(int i=0;i<n;i++){
        ll x=0,y=0;
        for (auto &p:d){
			int f=0;
            if(x<a[i].F)f+=1,x+=p;
            else x-=p;
            if(y<a[i].S)f+=2,y+=p;
            else y-=p;
            printf("%c",dir[f]);
        }
        puts("");
    }
}