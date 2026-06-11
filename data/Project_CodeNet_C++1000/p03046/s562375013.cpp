#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n,k;
	cin>>n>>k;
	if(n==1){
		if(k==0){
			cout<<"1 1 0 0";
		}else cout<<-1;
		RE 0;
	}
	int m=(1<<n);
	if(k>=m){
		cout<<-1;RE 0;
	}
	FOR(i,0,m-1)if(i!=k)cout<<i<<' ';
	cout<<k<<' ';
	for(int i=m-1;i>=0;i--)if(i!=k)cout<<i<<' ';
	cout<<k;
	RE 0;
}


