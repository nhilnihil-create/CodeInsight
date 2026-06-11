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

int main()
{
	int N;
	vec(D);
	cin >> N;
	map<int, int> K;
	K[0]++;
	fx(N) {
		vecp(D);
		K[D[x]]++;
	}

	fx(13) {
		if (K[x]>2||(x==0&&K[x]==2)) {
			ce(0);
			return 0;
		}
	}
	int ans = 0;
	vec(A);
	vec(B);
	fx(13) {
		if (K[x]==2) {
			pb(A, x );
			pb(A, 24 - x);
		}
		else if (K[x]==1) {
			pb(B, x);
		}
	}

	fx(1<<(B.size())) {
		vector<int> C(A);
		fy(B.size()) {
			if ((x&(1<<y))==0) {
				pb(C, B[y]);
			}
			else {
				pb(C, 24 - B[y]);
			}
		}
		sorts(C);
		int mini = 100;
		fy((int)C.size()-1) {
			mini = min(mini, abs(C[y] - C[y + 1]));
		}
		ans = max(ans, min(mini,C[0]+24-C[C.size()-1]));
	}
	ce(ans)

    return 0;
}

