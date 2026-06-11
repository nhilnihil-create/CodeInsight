#include "bits/stdc++.h"
#include <unordered_set>
#define rep(i,n) for(ull i = 0; i < n; i++)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define vll vector<vector<long long>>
#define vl vector<long long>
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define pf push_front
#define ld long double
#define Sort(a) sort(a.begin(),a.end())
#define cSort(a,cmp) sort(a.begin(),a.end(),cmp)
#define reSort(a) sort(a.rbegin(), a.rend())
static const ll llMAX = numeric_limits<long long>::max();
static const int intMAX = numeric_limits<int>::max();
static const ll  llMIN = numeric_limits<long long>::min();
static const int intMIN = numeric_limits<int>::min();
static const ll d_5 = 100000;
static const ll d9_7 = 1000000007;
static const ll d_9 = 1000000000;
static const double PI=3.14159265358979323846;

template<class T>
void Printvector(std::vector<T> a){
  int size = a.size();
  rep(i,size){
    cout<<a[i]<<" ";
  }
  cout<<endl;
}
template<class T>
void Printvector(std::vector<std::vector<T>> a){
  int size = a.size();
  rep(i,size){
    int size2=a[i].size();
    rep(j,size2){
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;
}
ll digitpower(ll a,ll b){//aのb乗を計算
  if(b==1){
    return a;
  }else if(b==0){
    return 1;
  }
  int mode=0;
  if(b%2==1){
    ll tmp = digitpower(a,(b-1)/2);
    if(mode==1){
      tmp%=d9_7;
    }
    tmp*=tmp;
    if(mode==1){
      tmp%=d9_7;
    }
    tmp*=a;
    if(mode==1){
      return tmp%d9_7;
    }else{
      return tmp;
    }
  }else{
    ll tmp = digitpower(a,(b)/2);
    if(mode==1){
      tmp%=d9_7;
    }
    tmp*=tmp;
    if(mode==1){
      tmp%=d9_7;
    }
    if(mode==1){
      return tmp%d9_7;
    }else{
      return tmp;
    }
  }
}

vl facs(2000010,-1);
ll Factrial(ll num){
  if(facs[num]!=-1){
    return facs[num];
  }
  if(num==1||num<=0){
    return 1;
  }else if(num<0){
    printf("ERROR_minus\n");
    return 0;
  }else{
    facs[num]=(num*Factrial(num-1))%d9_7;
    return facs[num];
  }
}
long long modinv(long long a, long long m) {//modの逆元

    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
}

vl invs(2000010,-1);
ll linercomb(ll n,ll k, ll mod){//n,kの線形時間で求める
if(n<k)return 0;
if(n<0)return 0;
if(k==0 || k==n)return 1;
  ll ans=Factrial(n);
  if(invs[k]==-1){
    invs[k]=modinv(Factrial(k),mod);
  }
  ans*=invs[k];
  ans%=d9_7;
  ll k1=Factrial(n-k);
  k1%=mod;
  ans*=modinv(k1,mod);
  ans%=mod;
  return ans;
}
unordered_map<ll,ll> prime_factor(int64_t n) {
  unordered_map<ll,ll> ret;
  for(int64_t i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

template<class T>
vector<T> getaccum(vector<T> a){
  int size=a.size();
  vector<T> ans(size);
  ans[0]=a[0];
  for(int i=0;i<size-1;i++){
    ans[i+1]=ans[i]+a[i+1];
    //ans[i+1]%=d9_7;
  }
  return ans;
}

ll getaccumnum(vector<ll> accum,int l,int r){//閉区間[l,r]の総和
  if(l==0){
    return accum[r];
  }else{
    return accum[r]-accum[l-1];
  }
}

struct datas{
  ll p;
  ll q;
};/*
bool cmp(const datas &a, const datas &b)
{
    return a.num < b.num;
}*/
template<class T>
T gcd(T a,T b){
  if(a==0){
    return b;

  }else if(b==0){
    return a;
  }
  while(1) {
    if(a < b) swap(a, b);
    if(!b) break;
    a %= b;
  }
  return a;
}
int LCS(string s,string t) {
  int n=s.size();
  int m=t.size();
  vector<vector<int>> dp=vector<vector<int>>(n+1,vector<int>(m+1,0));
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            if (s[i] == t[j]) {
                dp[i+1][j+1] = dp[i][j] + 1;
            }
            else {
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }
    return dp[n][m];
}


int main(void){
  int m;
  ull k;
  cin>>m>>k;
  if((1<<m) <= k){
    cout<<-1<<endl;
    return 0;
  }
  if(m==0){
    if(k==0){
      cout<<"0 0"<<endl;
      return 0;
    }else{
      cout<<-1<<endl;
    }
  }else if(m==1){
    if(k==0){
      cout<<"0 0 1 1"<<endl;
      return 0;
    }else{
      cout<<-1<<endl;
    }
  }else if(m>=2){
    rep(i,1<<m){
      if(k==i)continue;
      cout<<i<<" ";
    }
    cout<<k<<" ";
    ull tmp=1<<m;
    rep(i,1<<m){
      if(k==(tmp-1-i))continue;
      cout<<(tmp-1-i)<<" ";
    }
    cout<<k<<endl;
  }
  return 0;
}

//<<std::setprecision(30)

//重複削除
 /* std::sort(vec.begin(), vec.end());
  vec.erase(std::unique(vec.begin(), vec.end()), vec.end());*/
