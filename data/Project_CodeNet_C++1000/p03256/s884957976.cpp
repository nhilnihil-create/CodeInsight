#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
typedef long long LL;
int N,M;
string s;
int A[200001];
bool used[200001];
vector<int> G[200001];

int a[200001];
int b[200001];

int main(){
	cin>>N>>M;
	cin>>s;
	REP(i,N){
		used[i]=true;
		a[i]=0;
		b[i]=0;
	}
	REP(i,N){
		if(s[i]=='A'){
			A[i]=0;
		}else{
			A[i]=1;
		}
	}
	REP(i,M){
		int aa,bb;
		cin>>aa>>bb;
		aa--;bb--;
		G[aa].push_back(bb);
		G[bb].push_back(aa);
		if(A[aa]==0){
			a[bb]++;
		}else{
			b[bb]++;
		}
		if(A[bb]==0){
			a[aa]++;
		}else{
			b[aa]++;
		}
	}
	vector<int>v;
	REP(i,N){
		if(a[i]==0||b[i]==0){
			v.push_back(i);
			used[i]=false;
		}
	}
	REP(i,v.size()){
		int x=v[i];
		REP(j,G[x].size()){
			int y=G[x][j];
			if(used[y]==true){
				if(A[x]==0){
					a[y]--;
				}else{
					b[y]--;
				}
				if(a[y]==0||b[y]==0){
					v.push_back(y);
					used[y]=false;
				}
			}
		}
	}
	bool check=false;
	REP(i,N){
		if(used[i]==true)check=true;
	}
	if(check){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
}

