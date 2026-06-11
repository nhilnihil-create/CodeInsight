#include<bits/stdc++.h>
using namespace std;
#define ll long long 
// memo  fixed  setprecision(20);
using vvll = vector<vector<ll>>;
ll mod =1000000007;
/*"itob" int to "N"base */           template<typename TypeInt> string itob(const TypeInt v, int base){static const char table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";string ret;static numeric_limits<TypeInt> t;TypeInt n = v;if (t.is_signed) {if (v < 0) n *= -1;}while (n >= base) {ret += table[n%base];n /= base;}ret += table[n];if (t.is_signed) {if (v < 0 && base == 10) ret += '-';}reverse(ret.begin(), ret.end());return ret;}
/*"chmin" a = MAX*/                  template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
/*"chmax" a = MIN*/                  template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
/*"ctoi"  char to int*/              int ctoi(char c) {return c-'0';}
/*"gcd"   MAX*/                      int gcd(ll a,ll b){return b?gcd(b,a%b):a;}
/*"lcm"   MIN*/                      int lcm(ll a,ll b){return a*b/gcd(a,b);}
/*"primecheck"If prime,return true.*/bool primecheck(ll n){if(n < 2) return false;else{for(int i = 2; i * i <= n; i++){if(n % i == 0) return false;}return true;}}
string  reverserange(string s,ll a,ll b){reverse(s.begin()+a-1,s.begin()+b); return s;}

int main(){
  int n;
  cin >> n;
  vector<int>a(n);
  for(int i=0;i<n;i++){
    cin >> a.at(i);}
  ll che = abs(a.at(n-1))+abs(a.at(0));
  for(int i=1;i<n;i++){
    che+=abs(a.at(i-1)-a.at(i));
    }
for(int i=0;i<n;i++){
   if(i==0){
     ll ans = che;
     ans-=abs(a.at(i));
     ans-=abs(a.at(i)-a.at(i+1));
     ans+=abs(a.at(i+1));
     cout <<ans<<endl;
     continue;
     }
  if(i==n-1){
    ll ans = che;
    ans-=abs(a.at(i));
    ans-=abs(a.at(i)-a.at(i-1));
    ans+=abs(a.at(i-1));
    cout<< ans<<endl;
    continue;
    }
  ll ans = che;
  ans-=abs(a.at(i)-a.at(i-1));
  ans-=abs(a.at(i)-a.at(i+1));
  ans+=abs(a.at(i-1)-a.at(i+1));
  cout << ans<<endl;
  }
  
}

