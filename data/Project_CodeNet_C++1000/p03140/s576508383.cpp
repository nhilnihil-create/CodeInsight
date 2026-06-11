#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using vi = vector<int>;
using vvi = vector<vi>;
#define ote(x) cout<<(x)<<endl
#define all(x) (x).begin(),(x).end()
#define rp(i,s,e) for(int i=(s);i<(e);++i)
#define rpz(i,e) rp(i,0,e)

int main(){
	int N; cin>>N;
	string A,B,C; cin>>A>>B>>C;

	int count = 0;
	rpz(i,N){
		char a,b,c; a=A[i];b=B[i];c=C[i];
		if(a!=b && b!=c && c!=a) count += 2;
		else if(a==b && b==c) count += 0;
		else if(a==b || a==c || b==c) count += 1;
	}

	ote(count);
}
