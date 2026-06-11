#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(a) cout << #a << ": " << a << endl
#define sz(a) int(a.size())
#define rep(i,n) for(int i=0;i<n;i++)
#define forr(i, st, en) for(int i = st; i < en; i++)
#define all(v) (v).begin(),(v).end()
#define fast cin.tie(0); ios::sync_with_stdio(false)

int32_t main(){ fast;
	int h,w, tt; cin>>tt>>h>>w;
	int answer = 0;
	while(tt--){
		int a, b; cin>>a>>b;
		answer += (a >= h && b >= w);
	}
	cout<<answer<<endl;
}
