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
#define ALL(a) a.begin(),a.end()
#define ff fflush(stdout)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int degree[10000+10];
vector<int> each[10000+10];
priority_queue<mp> q;
int used[10000+10];
int res=0;
vector<int> c;
int color[10000+10];
int main(){
	int n;
	cin>>n;
	rep(i,n-1){
		int ai,bi;
		scanf("%d %d",&ai,&bi);
		degree[ai]++;
		degree[bi]++;		
		each[ai].PB(bi),each[bi].PB(ai);
	}
	rb(i,1,n) {
		int ci;
		scanf("%d",&ci);
		c.PB(ci);
	}c.PB(0);
	sort(ALL(c));
	
	rb(i,1,n){
		q.push(II(-degree[i],i));
	}
	rb(i,1,n){
		while(used[q.top().SEC]) q.pop();
		mp now=q.top();
		q.pop();
//		cout<<now.SEC<<" "<<degree[now.SEC]<<" "<<c[i]<<endl;
		used[now.SEC]=1;
		color[now.SEC]=c[i];
		now.FIR*=-1;
		res+=degree[now.SEC]*c[i];
		for(auto it:each[now.SEC]){
			degree[it]--;
			q.push(II(-degree[it],it));
		}
	}
	cout<<res<<endl;
	rb(i,1,n) cout<<color[i]<<" ";cout<<endl;
	return 0;
}
