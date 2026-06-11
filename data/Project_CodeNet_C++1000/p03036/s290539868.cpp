#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin, (x).rend()
#define endl '\n'
#define F first
#define S second
typedef pair<int,int> pii;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int r,d,x; cin>>r>>d>>x;
	int cnt = 10;
	ll op = x*1ll;
	while(cnt--){
		op = r*op -d; 
		cout<<op<<endl;
	}
	return 0;
}
