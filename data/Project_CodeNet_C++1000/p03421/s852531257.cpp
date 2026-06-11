#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define sz size()
#define pb(x) push_back(x) 
#define bg begin()
#define ed end()
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
int main(){
	ll N,A,B; cin>>N>>A>>B;
	//A=2 B=3 {5,6}{3,4}{1,2} N=6
	//A=2 B=3 {5}{3}{1,2} N=A+B-1(限界)
	//A=3 B=4 {10,11,12}{7,8,9}{4,5,6}{1,2,3}
	//A=3 B=4 {10,*,*}{7,*,*}{4,5,*}{1,2,3}->7,6,4,5,1,2,3

	if(N<A+B-1 || A*B<N) cout<<-1;
	else{//A+B-1<=N<=A*B　OK
		ll W=A*B-N;//消す数
		//{A*B-(A-1) ... A*B}...{A*1-(A-1) ... A*1}
		ll X=(A!=1ll?W/(A-1):0ll);//まとまり
		ll Y=(A!=1ll?W%(A-1):0ll);//あまり
		for(int i=1;i<=B;i++){
			if(i<=X){
				cout<<A*(B+1-i)-(A-1)-(W-i*(A-1))<<" ";
			}
			else if(i==X+1 && Y>0){
				rep(j,A-Y){
					cout<<A*(B+1-i)-(A-1)+j<<" ";
				}
			}
			else{
				rep(j,A){
					cout<<A*(B+1-i)-(A-1)+j<<" ";
				}
			}
		}
	}
}