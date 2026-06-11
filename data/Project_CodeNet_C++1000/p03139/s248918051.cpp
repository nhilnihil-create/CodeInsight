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
	int N,A,B; cin>>N>>A>>B;
	int mini, maxi;

	if(N<A+B){
		mini = A+B-N;
	}
	else{
		mini = 0;
	}
	if(A>B){
		maxi = B;
	}
	else{
		maxi = A;
	}

	cout<<maxi<<" "<<mini<<endl;
}
