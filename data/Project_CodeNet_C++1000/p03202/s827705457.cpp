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

map<int,int>f;
struct node{
	priority_queue<int>q;
	void clear(){
		for (;!q.empty();)q.pop();
	}
	void push(int x){
		q.push(x);
	}
	void upd(int x){
		//q.top()>x  f[q.top()]=0
		for (;!q.empty();){
			int t=q.top();
			if (t>x){
				f[t]=0;
				q.pop();
			}
			else return ;
		}
	}
}q;
#define M 200005
int a[M],n;
bool chk(int l){
	q.clear();
	f.clear();
	q.push(1);
	if (a[1]!=1){
		q.push(a[1]);
	}
	int i,x;
	for (i=2;i<=n;i++){
		if (a[i]>a[i-1]){
			q.push(a[i]);
		}
		else if (a[i]==a[i-1]){
			x=a[i];
			f[x]++;
			for (;f[x]==l;){
				if (x==1)return 0;
				f[x]=0;
				f[x-1]++;
				x--;
				q.push(x);
			}
		}
		else{
			x=a[i];
			q.upd(x);
			q.push(x);
			f[x]++;
			for (;f[x]==l;){
				if (x==1)return 0;
				f[x]=0;
				f[x-1]++;
				x--;
				q.push(x);
			}
		}
	}
	return 1;
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	read(n);
	int i,l,r,mid,res=0;
	for (i=1;i<=n;i++){
		read(a[i]);
	}
	int fl=1;
	for (i=2;i<=n;i++)if (a[i-1]>=a[i])fl=0;
	if (fl){
		printf("1\n");
		return 0;
	}
	l=2; r=n;
	for (;l<=r;){
		mid=(l+r)>>1;
		if (chk(mid)){
			r=mid-1;
			res=mid;
		}
		else{
			l=mid+1;	
		}
	}
	printf("%d\n",res);
	return 0;
}