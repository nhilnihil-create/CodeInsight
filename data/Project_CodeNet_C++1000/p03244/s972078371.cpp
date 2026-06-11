#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define chmin(a,b) if((a)>(b)) (a)=(b);
#define chmax(a,b) if((a)<(b)) (a)=(b);
#define vi vector<int>
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define pb push_back
#define pf push_front
int gcd(int a,int b){/*a>=0,b>=0,￢(a=b=0)*/
  while(min(a,b)>0){if(a<b)swap(a,b);a%=b;}return max(a,b);
}
int dx[]={1,0,-1,0,1,-1,-1,1};
int dy[]={0,1,0,-1,1,1,-1,-1};
const int MOD = 1e9+7;
const long long INF = 1e18+10;

/*--------------------------------------------------------------------*/

signed main(){
	int n;cin>>n;
	vi v(n);
	rep(i,n)cin>>v[i];

	vector<pii> cnt1(1e5+1,make_pair(0,0)),cnt2(1e5+1,make_pair(0,0));

	rep(i,1e5+1){
		cnt1[i].second=i;
		cnt2[i].second=i;
	}

	rep(i,n/2){
		cnt1[v[2*i]].first++;
		cnt2[v[2*i+1]].first++;
	}
	sort(all(cnt1));
	sort(all(cnt2));
	reverse(all(cnt1));
	reverse(all(cnt2));



	if(cnt1[0].second!=cnt2[0].second){
		cout<<n-cnt1[0].first-cnt2[0].first<<endl;
	}else if(cnt1[1].first+cnt2[0].first>=cnt1[0].first+cnt2[1].first){
		cout<<n-cnt1[1].first-cnt2[0].first<<endl;
	}else{
		cout<<n-cnt1[0].first-cnt2[1].first<<endl;
	}
	return 0;


}
