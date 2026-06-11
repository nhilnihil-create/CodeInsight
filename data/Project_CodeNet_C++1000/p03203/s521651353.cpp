//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int up_bound,low_bound;
vector<int> each[200000+10];
int main() {
	int h,w;
	cin>>h>>w;
	int n;
	cin>>n;
	rep(i,n){
		int x,y;
		scanf("%d %d",&x,&y);
		each[y].PB(x);
	}
	int res;
	low_bound=h;
	up_bound=1;
	for(auto it: each[1]){
		low_bound=min(low_bound,it-1);
	}
	res=low_bound;
	rb(i,2,w){
		up_bound++;
		sort(each[i].begin(),each[i].end());
		for(auto it: each[i]){
			if(it>low_bound) break;
			if(it<up_bound) continue;
			if(it==up_bound) up_bound++;
			else low_bound=it-1; 
		}
		res=low_bound;
	}
	cout<<res<<endl;
	return 0;
}
