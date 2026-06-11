#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <list>
#include <cstdio>
#define INF 1000000000000
#define MOD 1000000007ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<m; i++)
#define FOR(i,n,m) for(long long i=n; i<m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=(ll)a.size()-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef long double ld;
using namespace std;

int main(){
  string s;
  cin >> s;
  int a[3] = { };
  REP(i, s.size())a[s[i]-'a']++;
  sort(a, a+3);
  if((a[1]-a[0]) < 2 && (a[2]-a[0]) < 2 && (a[2]-a[1]) < 2) cout << "YES" << endl;
  else cout << "NO" << endl;
	return 0;
}