#include<iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define what_is(x) cerr << #x << " is " << x << endl;
#define MT make_tuple
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define FOR(i,n) for (int i=0;i < n ; i++)
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
bool bfsconnected(int *a, int i, int j,int n){
	queue<int> q;
	//bool conn=false;
	bool visited[n];
	FOR(i,n) visited[i]=false;
	/**(a+i*n+j)=0;
	*(a+j*n+i)=0;
*/
	q.push(i);
	while(!q.empty()){
		int s=q.front();
		q.pop();
		visited[s]=true;
		FOR(k,n) {
			if(*(a+n*s+k)==1 && k==j && s!=i) return true;
			else if(*(a+n*s+k )==1 && !visited[k] && (s!=i || k!=j)) q.push(k);
		}
	}
	return false;
}


int main(){
	int n,m;
	cin >> n >> m;
	int s,t;
	int *edges=new int[n*n];
	FOR(i,n) FOR(j,n) *(edges+i*n+j)=0;
	

	FOR(i,m){
		cin >> s >>t;
		*(edges+(s-1)*n+t-1)=1;
		*(edges+(t-1)*n+s-1)=1;
	}

	//FOR(i,n) FOR(j,n) cout << *(edges+i*n+j) <<" \n"[j==n-1];
	int sum=0;
	for(int i=0; i < n;i++){
		for(int j=0;j<=i;j++){
			if(*(edges+i*n+j)==1) {
				
				if(!bfsconnected(edges,i,j,n)) sum++;//cout << i+1 <<" "<<j+1 <<"\n";
			}
		}	
	}
	cout << sum;
	 

	return 0;
}