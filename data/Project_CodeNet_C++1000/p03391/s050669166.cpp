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
题意:
有两个序列A和B,然后两个人轮流操作
Satori希望操作次数尽可能多,每次操作都会选择序列的一个正数项,然后--
Koishi希望操作次数尽可能少,每次操作都会选择序列的一个正数项,然后--

求最后的操作次数?
分析:
感觉很玄妙啊...又是分类讨论吗?
如果A<B那么可以一直-- 然后就必须要怎么怎么.
如果A=B的话那么同理...?
否则A>B那么可以先把剩下的东西都给搞掉,然后乱来...?
*/
#define M 200005
int n,a[M],b[M],mx;
ll sum;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen("1.in","r",stdin);
	read(n);
	mx=1e9;
	int i,flag=1;
	for (i=1;i<=n;i++){
		read(a[i]); read(b[i]);
		sum+=a[i];
		if (a[i]>b[i]){
			Min(mx,b[i]);
		}
		if (a[i]!=b[i]){
			flag=0;
		}
	}
	if (flag){
		printf("0\n");
		return 0;
	}
	printf("%lld\n",sum-mx);
	return 0;
}