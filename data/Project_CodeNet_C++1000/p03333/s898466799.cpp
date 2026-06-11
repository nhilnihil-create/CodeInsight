#include <cstdio>
#include <set>
#define mp make_pair
#define FR first
#define SE second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=100010;
int n;
int a[N][2];
set<pii> l,r;
inline ll max(ll x,ll y){
	return x>y?x:y;
}
void readData(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i][0],&a[i][1]);
	a[n+1][0]=0; a[n+1][1]=0;
}
void addseg(int i){
	l.insert(mp(a[i][0],i));
	r.insert(mp(a[i][1],i));
}
void remseg(int i){
	l.erase(l.find(mp(a[i][0],i)));
	r.erase(r.find(mp(a[i][1],i)));
}
void initSet(){
	for(int i=1;i<=n;i++)
		addseg(i);
}
void move(int &cur,ll &sum,int t){
	if(a[t][0]<=cur&&cur<=a[t][1])
		return;
	else if(cur<a[t][0]){
		sum+=a[t][0]-cur;
		cur=a[t][0];
	}
	else{
		sum+=cur-a[t][1];
		cur=a[t][1];
	}
}
void goleft(int &cur,ll &sum){
	static set<pii>::iterator it;
	it=r.begin();	
	int id=(*it).SE;
	move(cur,sum,id);
	remseg(id);
}
void goright(int &cur,ll &sum){
	static set<pii>::iterator it;
	it=l.end();
	it--;
	int id=(*it).SE;
	move(cur,sum,id);
	remseg(id);
}
ll solve(int f){
	ll res=0;
	int cur=0;
	initSet();
	for(int i=1;i<=n;i++)
		if(i&1^f)
			goleft(cur,res);
		else
			goright(cur,res);
	move(cur,res,n+1);
	return res;
}
int main(){
	readData();
	printf("%lld\n",max(solve(0),solve(1)));
	return 0;
}