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
/*"gcd"   MAX Euclidean */           ll gcd(ll a,ll b){if(b==0)return a; return gcd(b,a%b);}
/*"lcm"   MIN*/                      ll lcm(ll a,ll b){ll g = gcd(a,b);return a/g*b;}
/*"primecheck"If prime,return true.*/bool primecheck(ll n){if(n < 2) return false;else{for(int i = 2; i * i <= n; i++){if(n % i == 0) return false;}return true;}}
string  reverserange(string s,ll a,ll b){reverse(s.begin()+a-1,s.begin()+b); return s;}
int main(){
   int n;
   cin >> n;
   vector<ll>a(n),b(n);
   ll sum =0;
   for(int i=0;i<n;i++){cin>>a.at(i);sum+=a.at(i);}
   for(int j=0;j<n;j++){cin>>b.at(j);sum-=b.at(j);}
   bool che = true;
   for(int i=0;i<n;i++){
      if(a.at(i)<b.at(i))che=false;
   }
   if(che){cout<<0<<endl;return 0;}
   if(sum<0){cout<<-1<<endl;return 0;}
   vector<ll>c(n);
   ll ans = 0;
   sum =0;
   for(int i=0;i<n;i++){
      c.at(i)= a.at(i)-b.at(i);
      if(c.at(i)<0){ans++;
      sum+=c.at(i);
      }
   }
   sort(c.begin(),c.end());
   reverse(c.begin(),c.end());
   for(int i=0;i<n;i++){
      if(sum>=0)break;
      ans++;
      sum+=c.at(i);
   }
   cout << ans << endl;
}
    

