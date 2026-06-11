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
#define vecsize(b,size) vector<int> (b)((size));
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
	int N, Q;
	cin >> N >> Q;
	string S;
	cin >> S;
	vector<pair<char, char>> T;
	fx(Q) {
		char t, d;
		cin >> t >> d;
		pb(T, make_pair(t, d));
	}

	int left = 0, right = N;
	int mid = (left + right) / 2;
	fx(50) {
		mid = (left + right) / 2;
		int res = 0;
		fy(Q) {
			if (S[mid]==T[y].first) {
				if (T[y].second=='L') {
					mid--;
					if (mid<0) {
						res = -1;
						break;
					}
				}
				else {
					mid++;
					if (mid>=N) {
						res = 1;
						break;
					}
				}
			}
		}
		if (res==0||res==1) {
			right = (left + right) / 2;
		}
		else if (res==-1) {
			left = (left + right) / 2;
		}
	}
	int ansL = (left + right) / 2;
	if (left==right) {
		ansL--;
	}

	 left = -1, right = N-1;
	 mid = (left + right+ 1) / 2;
	fx(50) {
		mid = (left + right+1) / 2;
		int res = 0;
		fy(Q) {
			if (S[mid] == T[y].first) {
				if (T[y].second == 'L') {
					mid--;
					if (mid < 0) {
						res = -1;
						break;
					}
				}
				else {
					mid++;
					if (mid >= N) {
						res = 1;
						break;
					}
				}
			}
		}
		if (res == 0||res==-1) {
			left = (left + right + 1) / 2;
		}
		else if (res == 1) {
			right = (left + right + 1) / 2;
		}
	}
	int ansR = (left + right + 1) / 2;
	if (left == right) {
		ansR++;
	}
	//doublece(ansL,ansR)
	if (ansL>=ansR) {
		ce(N - ansL - 1-N + ansR + abs(ansL-ansR)+1)
	}
	else {
		ce(N-ansL - 1 -N+ansR)
	}

    return 0;
}

