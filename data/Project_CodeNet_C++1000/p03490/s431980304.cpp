#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<ll>
#define sortv(a); sort(a.begin(), a.end());
#define rev(a); reverse(a.begin(), a.end());
#define FOR(i,a,b) for (ll i = (ll)(a); i < (b); i++)
#define ROF(i,a,b) for (ll i = (ll)(b)-1; i >= (a); i--)
#define printarray(a) FOR(Q,0,(int)(a).size()) cout<<(a)[Q]<<" "; cout<<'\n';

ll MOD = 1000000007;
ll INF = 1LL << 60;

/*****************************************************************************/
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;cin>>s;
	int n=(int)s.length();
	int x,y;cin>>x>>y;
	vec hor;
	vec ver;
	bool flat=1;
	int cnt=0;
	bool minused=false;
	FOR(i,0,n) {
		if (s[i]=='F') {
			cnt++;
		}else{
			if (flat) {
				if (!minused) {
					x-=cnt;
					minused=true;
				} else {
					hor.push_back(cnt);
				}
			}else{
				ver.push_back(cnt);
			}
			cnt=0;
			flat^=1;
		}
	}
	if(cnt>0) {
		if (flat) {
			if (!minused) {
				x-=cnt;
				minused=true;
			} else {
				hor.push_back(cnt);
			}
		}else{
			ver.push_back(cnt);
		}	
	}

	sortv(hor);rev(hor);
	sortv(ver);rev(ver);

	int h=0;
	FOR(i,0,(int)hor.size()) {
		if (h>x) {
			h-=hor[i];
		} else {
			h+=hor[i];
		}
	}
	int v=0;
	FOR(i,0,(int)ver.size()) {
		if (v>y) {
			v-=ver[i];
		} else {
			v+=ver[i];
		}
	}

	// printarray(hor);
	// printarray(ver);
	// cout<<h<<" "<<v<<endl;

	if (h==x&&v==y) {
		cout<<"Yes";
	} else {
		cout<<"No";
	}
}