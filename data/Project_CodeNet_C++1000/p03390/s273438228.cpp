//2018年09月13日 星期四 22时16分19秒 
#include<bits/stdc++.h>
#define ll long long
#define db double
#define lowbit(p) (p&(-p))
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define A first
#define B second
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
void Max(int &x,int y){
	if (x<y)x=y;
}
void Min(ll &x,ll y){
	if (x>y)x=y;
}
void Max(ll &x,ll y){
	if (x<y)x=y;
}
/*
## 题意:
给出A,B
求有多少个数对(x,y)满足x*y<A*B
并且x各不相等 y各不相等
*/
ll chk(ll x){
	ll l=0,r=1e9,mid,res;
	for (;l<=r;){
		mid=(l+r)>>1;	
		if (mid*mid<=x){
			res=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	return res;
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen("1.in","r",stdin);
	int q;
	ll a,b,res,k;
	read(q);
	for (;q--;){
		read(a); read(b);
        k=chk(a*b-1);
        res=2*k-1;
        if(k*(k+1)>a*b-1)res--;
        if(a==b)res++;
    	printf("%lld\n",res);
    }
	return 0;
}