#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1e9+7,INF=mod*mod*3;
#define rep(i,N) for(ll i=0; i<(N); i++)
#define rep1(i,N) for(ll i=1; i<(N); i++)
#define pb push_back

ll A,B;
int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>A>>B; 

ll XorB;
if(B%4==0) XorB=B;
if(B%4==1) XorB=1;
if(B%4==2) XorB=B+1;
if(B%4==3) XorB=0;
ll XorA;
if(A-1>=0){
	if((A-1)%4==0) XorA=A-1;
	if((A-1)%4==1) XorA=1;
	if((A-1)%4==2) XorA=A;
	if((A-1)%4==3) XorA=0;
}

if(A-1>=0){
	cout<<(XorA^XorB)<<endl;
}else{
	cout<<XorB<<endl;
}


}
	
