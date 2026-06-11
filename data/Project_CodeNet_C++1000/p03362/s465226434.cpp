#include <bits/stdc++.h>
using namespace std; 
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(int i=n; i>-1; --i)
#define ALL(a) (a).begin(),(a).end()
#define INIT(a,n,x); REP(i,(n)){ (a)[i]=(x); }
#define CINA(a,n); REP(i,(n)){ cin >> (a)[i]; }
#define INIT2(a,n,m,x); REP(i,(n)){ REP(j,(m)){(a)[i][j]=(x);} }
#define CINA2(a,n,m); REP(i,(n)){ REP(j,(m)){cin >> (a)[i][j];} }
#define LINY "YES\n"
#define Liny "Yes\n"
#define LINN "NO\n"
#define Linn "No\n"
#define unordered_map umap
typedef long long ll;
typedef long double ld;
ll min(ll x,ll y){return (x<y ? x:y);}
ll max(ll x,ll y){return (x>y ? x:y);}
int keta(ll x){ if(x<10){return 1;} else{return keta(x/10) + 1;}}
int keta_wa(ll x){ if(x<10){return x;} else{return keta_wa(x/10) + x%10;} }
int ctoi(char c){ return ( (c>='0' && c<='9')? c - '0': 0 );}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){if(a<b){swap(a,b);} return a*b /gcd(a,b);}
bool isPrime(int n){if(n<2){return false;}for(int i=2;i<sqrt(n)+1;i++){if(n%i==0) return false;}return true;}

int main(){
  int L = 55555+1;
  bool prime[L];
  vector<int> pv = {2};
  int count = 0;
  int N; cin >>N;
  for(int i=3;i<L;i++){
    bool fp = true;
    for(int x:pv){ if(i%x==0){fp = false;break;} }
    if(fp){
      if(i%5==3){
	    printf("%d ",i);
    	count++;
      	if(count==N) break;
      }
      pv.push_back(i);
    }
  }
}
