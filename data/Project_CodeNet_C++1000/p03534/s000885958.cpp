#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#include <complex>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL-1
double EPS=1e-9;
using namespace std;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
typedef complex<double> P;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }
long long int MOD = 1000000007;
/*
cin >> n;
vi a(n);
rep(i,n)cin>>a[i];
*/
int n;
bool used[350];
int main(){
	string str;
	cin>>str;
	int cnt[30]={0};
	for(int i=0;i<str.size();i++){
		cnt[str[i]-'a']++;
	}
	int ma=0;
	for(int i=0;i<30;i++){
		ma=max(ma,cnt[i]);
	}
	//cout<<ma<<endl;
	int n=str.size();
	if(ma>(n+2)/3){
		cout<<"NO"<<endl;
	}else{
		cout<<"YES"<<endl;
	}
}