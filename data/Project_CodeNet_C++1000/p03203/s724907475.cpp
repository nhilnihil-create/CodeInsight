#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)
const ll mod=1000000007;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int h,w,n;cin >> h >> w >> n;
	vector<pii> xy(n);
	map<pii,int> m;
	rep(i,n){
		cin >> xy.at(i).first >> xy.at(i).second;
		m[mp(xy.at(i).first,xy.at(i).second)]++;
	}
	vector<int> a(h+1,1);
	int j=1;
	for(int i=2;i<=h;++i){
		if(m[mp(i,j+1)]==0){
			j++;
		}
		a.at(i)=j;
	}
	sort(xy.begin(),xy.end());
	int ans=h;
	rep(i,n){
		if(a[xy.at(i).first-1]>=xy.at(i).second){
			ans=xy.at(i).first-1;
			break;
		}
	}
	cout << ans << endl;
}