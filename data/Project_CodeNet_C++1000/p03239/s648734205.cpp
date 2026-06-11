#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define INF 1000000000000
#define MOD 1000000007
#define MAXR 100000
#define _GLIBCXX_DEBUG
 
int threemax(int a, int b, int c) {
	if (a >= b && a >= c) {
		return a;
	}
	else if (b >= a && b >= c) {
		return b;
	}
	else {
		return c;
	}
}
 
int threemin(int a, int b, int c) {
	if (a <= b && a <= c) {
		return a;
	}
	else if (b <= a && b <= c) {
		return b;
	}
	else {
		return c;
	}
}
 
void chmaxl(ll &a,ll b){
	if(a<b){
		a=b;
	}
	return;
}
 
void chminl(ll &a,ll b){
	if(a>b){
		a=b;
	}
	return;
}
 
void chmaxi(int &a,int b){
	if(a<b){
		a=b;
	}
	return;
}
 
void chmini(int &a,int b){
	if(a>b){
		a = b;
	}
	return;
}
 
 
 
int main() {
  int N,T;
  cin >> N >> T;
  int ans=10000;
  vector<int> cvec(N);
  vector<int> tvec(N);
  for(int i=0;i<N;i++){
    cin >> cvec.at(i) >> tvec.at(i);
    if(tvec.at(i)<=T&&cvec.at(i)<ans){
      ans=cvec.at(i);
    }
  }
  if(ans==10000){
    cout << "TLE";
  }
  else{
    cout << ans;
  }
}