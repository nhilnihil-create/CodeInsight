#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<map>
#include<string.h>
#include<complex>
#include<math.h>
#include<queue>
#include <functional>
#include<time.h>
#include <stack>
#include<iomanip>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define ll long long
#define llint long long int
#define reverse(v)  reverse(v.begin(), v.end());
#define Yes(ans) if(ans)cout<<"Yes"<<endl; else cout<<"No"<<endl;
#define YES(ans) if(ans)cout<<"YES"<<endl; else cout<<"NO"<<endl;
#define hei(a) vector<a>
#define whei(a) vector<vector<a>>
#define UF  UnionFind 
#define Pint pair<int,int>
#define Pll pair<llint,llint>
#define keta(a)  fixed << setprecision(a)
constexpr auto mod = 1000000007;
//辞書順はnext_permutation( begin( v ), end( v ) );やで！
const llint INF = 100000000;

struct edge { int to, cost; };
int main() {
	string s;
	cin >> s;
	int ans = 0;
	while (s.size()>1) {
		if (s[0] == s[s.size() - 1]) {
			if (s.size() == 2)break;
			s = s.substr(1, s.size() - 2);
		}
		else {
			if (s[0] == 'x') {
				ans++;
				s = s.substr(1, s.size() - 1);
			}
			else if (s[s.size() - 1] == 'x') {
				ans++;
				s=s.substr(0,s.size()-1);
	        }
			else {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
