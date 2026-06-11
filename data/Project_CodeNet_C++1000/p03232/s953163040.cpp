#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
#include<cassert>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
//問題文および制約はちゃんと確認しよう！
//サイズは10^5じゃなくて2×10^5とかかもしれないし、重要な制約・条件を見落としているかも
//とりあえずサンプルを読んでから解法を考えよう？
lint extgcd(lint a, lint b, lint &x, lint &y) {
  lint g = a; x = 1; y = 0;
  if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
  return g;
}
lint invMod(lint a, lint m) {
  lint x, y;
  if (extgcd(a, m, x, y) == 1) return (x + m) % m;return 0;
}
lint sum[100100],a[100100];
lint mo=1000000007,out=0;
int main()
{
	int n;
	cin>>n;
	rep(i,n) cin>>a[i];
	sum[0]=0;
	rep(i,100010) sum[i+1]=(sum[i]+invMod(i+1,mo))%mo;
	rep(i,n){
		out+=a[i]*(sum[i+1]+sum[n-i]-1);
		out%=mo;
	}
	REP(i,1,n+1){
		out*=i;out%=mo;
	}
	cout<<out<<endl;
}
