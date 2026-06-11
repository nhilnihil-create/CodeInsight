#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define mp make_pair
#define vi vector<int>
#define fi first
#define se second

typedef long long ll;
const int N = 1e5 + 1;

pii lr[N], li[N], ri[N];

int main(){
	int n;
	ll lans = 0, rans = 0, ans;
	cin >> n;
	for(int i = 0; i < n; i++){
		int l, r;
		cin >> l >> r;
		lr[i] = mp(l, r);
		li[i] = mp(l, i);
		ri[i] = mp(r, i);
	}
	sort(ri, ri+n);
	sort(li, li+n);
	vi gr(n), gl(n);
//	cout << li[0].fi << " " << li[1].fi << endl;
	int cur = 0, l = 0, r = n-1;
	for(int i = 0; i < n; i++){
		if(i % 2){
			while(gr[ri[l].se])
				l++;
			if(ri[l].fi > cur)
				break;
			else{
				rans += cur-ri[l].fi;
				gr[ri[l].se]++;
				cur = ri[l].fi;
//				cout << "went left " << cur << " rans = " << rans << endl;
			}
		}else{
			while(gr[li[r].se])
				r--;
			if(li[r].fi < cur)
				break;
			else{
				rans += li[r].fi - cur;
				cur = li[r].fi;
				gr[li[r].se]++;
//				cout << "went right " << cur << " rans = " << rans << endl;
			}
		}
	}
	rans += abs(cur);
	cur = l = 0;
	r = n-1;
	for(int i = 0; i < n; i++){
		if(i % 2 == 0){
			while(gl[ri[l].se])
				l++;
			if(ri[l].fi > cur)
				break;
			else{
				lans += cur-ri[l].fi;
				gl[ri[l].se]++;
				cur = ri[l].fi;
			}
		}else{
			while(gl[li[r].se])
				r--;
			if(li[r].fi < cur)
				break;
			else{
				lans += li[r].fi - cur;
				cur = li[r].fi;
				gl[li[r].se]++;
			}
		}
	}
	lans += abs(cur);
	cout << max(lans, rans) << endl;
	return 0;
}