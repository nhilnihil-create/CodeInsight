#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << (x) << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){
	return o<<"("<<p.fs<<","<<p.sc<<")";
}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){
	o<<"{";
	for(const T& v:vc) o<<v<<",";
	o<<"}";
	return o;
}
using ll = long long;
template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;
int e[1000][1000];
int main(){
	int N;
	cin>>N;
	rep1(k,10000){
		if(k*(k-1)/2 == N){
			int I = 1;
			rep(i,k) rep(j,i) e[i][j] = e[j][i] = I++;
			puts("Yes");
			cout<<k<<endl;
			rep(i,k){
				cout<<k-1;
				rep(j,k) if(j!=i) cout<<" "<<e[i][j];
				cout<<endl;
			}
			return 0;
		}
	}
	puts("No");
}