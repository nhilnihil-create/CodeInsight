#include<bits/stdc++.h>
#define ll long long
#define db double
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define A first
#define B second
#define lowbit(p) (p&(-p))
using namespace std;
void read(int &x){
	x=0; char c=getchar(); int p=1;
	for (;c<48;c=getchar())if (c=='-')p=-1;
	for (;c>47;c=getchar())x=(x<<1)+(x<<3)+(c^48);
	x*=p;
}
void read(ll &x){
	x=0; char c=getchar(); int p=1;
	for (;c<48;c=getchar())if (c=='-')p=-1;
	for (;c>47;c=getchar())x=(x<<1)+(x<<3)+(c^48);
	x*=p;
}
void Min(int &x,int y){
	if (x>y)x=y;
}
void Min(ll &x,ll y){
	if (x>y)x=y;
}
void Max(int &x,int y){
	if (x<y)x=y;
}
void Max(ll &x,ll y){
	if (x<y)x=y;
}
#define M 200005
set<int>q[M];
int main(){
//	freopen("1.in","r",stdin);
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int h,w,n,x,y,res;
	read(h); read(w); read(n);
	for (int i=1;i<=n;i++){
		read(x); read(y);
		q[x].insert(y);
	}
	int tmp=1;
	for (int i=1;i<h;i++){
		if (q[i+1].size()&&*q[i+1].begin()<=tmp){
			printf("%d\n",i);
			return 0;
		}
		else{
			if (!q[i+1].count(tmp+1))tmp++;
		}
	}
	printf("%d\n",h);
	return 0;
}