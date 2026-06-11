#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fw(p) for(int w=0;w<(p);w++)
#define fx(p) for(int x=0;x<(p);x++)
#define fy(p) for(int y=0;y<(p);y++)
#define fz(p) for(int z=0;z<(p);z++)
#define fyg(p,g) for(int y=(g);y<(p);y++)
#define fzg(p,g) for(int z=(g);z<(p);z++)
#define ce(d) cout<<d<<endl;
#define vecp(p) int aa;cin>>aa;(p).push_back(aa);
#define vecpl(p) long long aa;cin>>aa;(p).push_back(aa);
#define vecps(p) string aa;cin>>aa;(p).push_back(aa);
#define vecp2(p) cin>>aa;(p).push_back(aa);
#define vecpl2(p) long long a	b;cin>>ab;(p).push_back(ab);
#define vecps2(p) string ab;cin>>ab;(p).push_back(ab);
#define sorts(c) sort((c).begin(),(c).end());
#define reverses(c) reverse((c).begin(),(c).end());
#define vec(b) vector<int> (b);
#define vecl(b) vector<long long> (b);
#define vecs(b) vector<string> (b);
#define pb(b,a) (b).push_back((a));
#define doublece(a,b) cout<<(a)<<' '<<(b)<<endl;
#define pairs(s) vector<pair<int,int>> (s);
#define pairsp(s) int aa,bb;cin>>aa>>bb;(s).push_back(make_pair(aa,bb));
#define MOD 1000000007
#define cey ce("Yes")
#define cen ce("No")
#define ceY ce("YES")
#define ceN ce("NO")
vecl(S);
vecl(T);
int bin1( ll x, int size) {
	int l = 0, r = size;
	while (r-l>1) {
		int mid = (l + r) / 2;
		if (S[mid]>x) {
			r = mid;
		}
		else {
			l = mid;
		}
	}

	return l;
}

int bin2(ll x, int size) {
	int l = 0, r = size;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (T[mid] > x) {
			r = mid;
		}
		else {
			l = mid;
		}
	}

	return l;
}

int main()
{
	int A, B, Q;

	cin >> A >> B >> Q;

	fx(A) {
		vecpl(S);
	}
	fx(B) {
		vecpl(T);
	}

	fy(Q) {
		ll x;
		cin >> x;
		int i = bin1( x, A);
		int j = bin2( x, B);
		ll ans = LLONG_MAX;
		for (int w = 0; w <= 1;w++) {
			if (i+w<0||i+w>=A) {
				continue;
			}
			for (int z = 0; z <= 1; z++) {
				if (j + z < 0 || j + z >= B) {
					continue;
				}
				ll s = S[i + w] - x, t = T[j + z] - x;
				ll ss = abs(s), tt = abs(t);
				if ((s>0&&t<0) || (t > 0&& s < 0)) {
					ans = min({ ans, abs(s) * 2 + abs(t), abs(t) * 2 + abs(s) });
				}
				else {
					ans = min(ans,max(abs(s), abs(t)));
				}

			}
		}
		ce(ans)
	}

    return 0;
}

