//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","r",stdin)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int a[200000+10],ex[200000+10];
int main(){
//	FREO;
	int n;
	cin>>n;
	rep(i,n) cin>>a[i],ex[i]=1;
	sort(a,a+n);
	LL is=1;
	while(is<=2000000000) is<<=1;
	int res=0;
	for(is;is>=1;){
		int r=n-1;
		rb(l,0,n-2){
			if(!ex[l]) continue; 
			r=max(r,l+1);
			while((a[r]+a[l]>is||!ex[r])&&r>=0) r--;
			if(r<=l) break;
			if(a[r]+a[l]==is){
				ex[r]=ex[l]=0;
				res++;
				continue;
			}
		}
		is>>=1;
	}
	cout<<res<<endl;
	return 0;
}