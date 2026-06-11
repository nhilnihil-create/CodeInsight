#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)

int main(){
	//input
	ll N,Z,W; cin>>N>>Z>>W;
	vector<ll> A(N);
    rep(i,N) cin>>A[i];

	if(N==1) cout<<abs(A[0]-W);
    else{
        cout<<max(abs(A[N-1]-W),abs(A[N-2]-A[N-1]));
    }
}