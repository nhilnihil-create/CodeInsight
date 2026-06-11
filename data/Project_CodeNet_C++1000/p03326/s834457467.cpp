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

struct cake {
	ll x;
	ll y;
	ll z;
};

int main()
{
	int N, M;
	cin >> N >> M;
	vector<cake> C;
	fw(N) {
		ll x, y, z;
		cin >> x >> y >> z;
		cake c;
		c.x = x;
		c.y = y;
		c.z = z;
		C.push_back(c);
	}
	ll ans = 0;
	fx(2) {
		fy(2) {
			fz(2) {
				vecl(V);
				fw(N) {
					ll x1 = x % 2 == 0 ? C[w].x : -C[w].x;
					ll y1 = y % 2 == 0 ? C[w].y : -C[w].y;
					ll z1 = z % 2 == 0 ? C[w].z : -C[w].z;
					pb(V, x1 + y1 + z1);
				}
				sorts(V)
				ll sum = 0;
				fw(M) {
					sum += V[N - 1 - w];
				}
				ans = max(ans, sum);
			}
		}
	}

	ce(ans)


    return 0;
}

