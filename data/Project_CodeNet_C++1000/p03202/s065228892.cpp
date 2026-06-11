#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
const int maxn=2e5+100;
int a[maxn];
map < int,int > mapa,mapb;
struct{
	int sum[maxn*4],id[maxn*4];
	void down(int x,int l,int r){
		if (sum[x]){
			sum[x*2]=sum[x];
			sum[x*2+1]=sum[x];
			sum[x]=0;
		}
	}
	void build(int x,int l,int r){
		sum[x]=0;
		if (l==r){
			id[l]=x;
			return;
		} 
		int mid=(l+r)/2;
		build(x*2,l,mid);
		build(x*2+1,mid+1,r);
	}
	int find(int x,int l,int r,int L,int xx){
//		cout << "find:" << x << ' ' << l << ' ' << r << ' ' << sum[x] << ' ' << L << ' ' << xx << endl;
		if (l==L && l==r){
			while (l && sum[id[l]]==xx){
				l--;
//				cout << "find repeat:" << l << ' ' << x << ' ' << sum[x] << endl;
			}
			return l;
		}
		down(x,l,r);
		int mid=(l+r)/2;
		if (L<=mid) return find(x*2,l,mid,L,xx);
		return find(x*2+1,mid+1,r,L,xx);
	}
	void update(int x,int l,int r,int L,int R,bool ope){
		if (l==L && r==R){
			sum[x]=ope?sum[x]+1:1;
			return;
		}
		down(x,l,r);
		int mid=(l+r)/2;
		if (L<=mid) update(x*2,l,mid,L,min(R,mid),ope);
		if (R>mid) update(x*2+1,mid+1,r,max(L,mid+1),R,ope);
	}
	void print(int x,int l,int r){
		cout << "print_seg:" << x << ' ' << l << ' ' << r << ' ' << sum[x] << endl;
		if (l==r) return;
		int mid=(l+r)/2;
		print(x*2,l,mid);
		print(x*2+1,mid+1,r);
	} 
}seg;
vector < int > ve;
void myinit2(){
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		mapa[a[i]]++;
	}
	map < int,int > :: iterator it;
//	for (it=mapa.begin();it!=mapa.end();it++){
//		cout << it->first << ' ' << it->second << endl;
//	}
	int last=0,befo=-1;
	for (it=mapa.begin();it!=mapa.end();it++){
		if (befo==-1) last=min(it->first,it->second);
		else last=min(last+(it->second),last+(it->first)-befo);
//		cout << it->first << ' ' << last << endl; 
		mapb[it->first]=last;
		befo=it->first;
	}
	for (int i=1;i<=n;i++){
		a[i]=mapb[a[i]];
	}
//	for (int i=1;i<=n;i++) cout << a[i] << ' ';cout << endl;
}
bool check(int x){
	seg.build(1,1,n);
	seg.update(1,1,n,1,a[1],0);
	for (int i=2;i<=n;i++){
		if (a[i]>a[i-1]) seg.update(1,1,n,a[i-1]+1,a[i],0);
		else{
//			seg.print(1,1,n);
			int id=seg.find(1,1,n,a[i],x);
//			cout << i << ' ' << id << endl;
			if (id==0) return false;
			seg.update(1,1,n,id,id,1);
			if (id<a[i]) seg.update(1,1,n,id+1,a[i],0);
		}
	}
	return true;
}
signed main(){
	myinit2();
//	cout << check(1) << endl;
//  return 0;
	int l=1,r=1e6;
	while (r-l>1){
		int mid=(l+r)/2;
		if (check(mid)) r=mid;
		else l=mid;
	}
//	cout << l << ' ' << r << endl;
	int ans=check(l)?l:r;
	cout << ans << endl;
	return 0;
}