#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>
#include<complex>
#include <cassert>

using namespace std;

#define ll long long
#define ld long double
#define INF 1e9
#define LINF (ll)INF*INF
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<(n);i++)
#define loop(i,a,n) for(int i=a;i<(n);i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

#define int ll //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

const double PI=acos(-1);
const double EPS=1e-9; //うまくいかなかったらゆるめる

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef pair<int,pii> pip;
typedef vector<pii> vp;
typedef vector<vi> vvi;

int gcd(int a, int b){if(b==0) return a;return gcd(b,a%b);}
int lcm(int a, int b){return a/gcd(a,b)*b;}


signed main(void) {
	string s;
	cin >> s;
	int ans = 0;
	rep(i,s.size()){
		int t = 0;
		while(i < s.size()){
			if(s[i] != 'A' && s[i] != 'C' && s[i] != 'G' && s[i] != 'T'){
				break;
			}else{
				t++;
				i++;
				ans = max(ans, t);
			}
		}
	}
	cout << ans << endl;

}
