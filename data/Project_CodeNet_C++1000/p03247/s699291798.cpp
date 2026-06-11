#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define EPS 1e-10
#define setNil(x) memset((x),0,sizeof(x))
#define setINF(x) memset((x),63,sizeof(x))
#define setNegINF(x) memset((x),192,sizeof(x)) //NegINF=-INF-1
#define setNeg1(x) memset((x),255,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1005;
int n,x[N],y[N];
vector<ll> d;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		if(((abs(x[i])+abs(y[i]))&1)!=((abs(x[1])+abs(y[1]))&1)){
			cout<<"-1\n";
			return 0;
		}
	}
	for(int i=31;~i;i--)d.push_back(1ll<<i);
	if(!(abs(x[1])+abs(y[1])&1))d.push_back(1);
	cout<<d.size()<<endl;
	for(int i=0;i<d.size();i++)cout<<d[i]<<' ';
	cout<<endl;
	for(int i=1;i<=n;i++){
		ll cx=x[i],cy=y[i];
		for(int j=0;j<d.size();j++){
			if(abs(cx)>abs(cy)){
				if(cx>0){
					cout<<'R';
					cx-=d[j];
				}
				else{
					cout<<'L';
					cx+=d[j];
				}
			}
			else{
				if(cy>0){
					cout<<'U';
					cy-=d[j];
				}
				else{
					cout<<'D';
					cy+=d[j];
				}
			}
		}
		cout<<endl;
	}
	return 0;
}