#include "bits/stdc++.h"
#define MAXN 100009
#define INF 1000000007
#define mp(x,y) make_pair(x,y)
#define all(v) v.begin(),v.end()
#define pb(x) push_back(x)
#define wr cout<<"----------------"<<endl;
#define ppb() pop_back()
#define tr(ii,c) for(__typeof((c).begin()) ii=(c).begin();ii!=(c).end();ii++)
#define ff first
#define ss second
#define my_little_dodge 46
#define debug(x)  cerr<< #x <<" = "<< x<<endl;
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;
template<class T>bool umin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T>bool umax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
PII arr[MAXN];
set<PII>l,r;
int main(){
    //~ freopen("file.in", "r", stdin);
    int n;
    scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		arr[i]=mp(x,y);
	}
	for(int i=0;i<n;i++){
		r.insert(mp(arr[i].ss,i));
		l.insert(mp(arr[i].ff,i));
	}
	ll a=0,b=0;
	int now=0;
	for(int i=0;i<n;i++){
		if(i%2==0){
			PII res=*l.rbegin();
			if(now<res.ff){
				a+=res.ff-now;
				now=res.ff;
				l.erase(res);
				r.erase(mp(arr[res.ss].ss,res.ss));
			}
		}
		else{
			PII res=*r.begin();
			if(res.ff<now){
				a+=now-res.ff;
				now=res.ff;
				r.erase(res);
				l.erase(mp(arr[res.ss].ff,res.ss));
			}
		}
	}a+=abs(now);
	now=0;l.clear();r.clear();
	for(int i=0;i<n;i++){
		r.insert(mp(arr[i].ss,i));
		l.insert(mp(arr[i].ff,i));
	}
	for(int i=0;i<n;i++){
		if(i&1){
			PII res=*l.rbegin();
			if(now<res.ff){
				b+=res.ff-now;
				now=res.ff;
				l.erase(res);
				r.erase(mp(arr[res.ss].ss,res.ss));
			}
		}
		else{
			PII res=*r.begin();
			if(res.ff<now){
				b+=now-res.ff;
				now=res.ff;
				r.erase(res);
				l.erase(mp(arr[res.ss].ff,res.ss));
			}
		}
	}b+=abs(now);
	printf("%lld\n",max(a,b));
	return 0;
}
