#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
#pragma GCC optimize("O3")
#define REP(i,n) for(int i=0;i<n;i++)
#define REPP(i,n) for(int i=1;i<=n;i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define EPS (1e-9)
#define INF (1e17)
#define PI (acos(-1))
//const double PI = acos(-1);
//const double EPS = 1e-15;
//long long INF=(long long)1E17;
#define i_7 (long long)(1e9+7)
//#define i_7 998'244'353
long mod(long a){
    long long c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
long long po(long a, long b){
    if(b==0){
        return 1;
    }
    
    long long z = po(a,b/2);
    z = mod(z*z);
    if(b%2!=0){
        z = mod(a*z);
    }
    return z;
}
using namespace std;
//using namespace boost::multiprecision;

bool prime_(int n){
  if(n==1){
    return false;
  }else if(n==2){
    return true;
  }else{
    for(int i=2;i<=sqrt(n);i++){
      if(n%i==0){
        return false;
      }
    }
    return true;
  }
}

long long gcd_(long long a, long long b){
  if(a<b){
    swap(a,b);
  }
  if(a%b==0){
    return b;
  }else{
    return gcd_(b,a%b);
  }
}
 
long long lcm_(long long x, long long y){
  return (x/gcd_(x,y))*y;
}

// Binary Indexed Tree (Fenwick Tree)
template<typename T> // T: type of cost
struct BIT {
    int n;
    vector<T> d;
    BIT(int n=0):n(n),d(n+1) {}
    //配列のインデックスiの要素d[i]に対して、xを加算する。
    void add(int i, T x=1) {
        for (i++; i <= n; i += i&-i) {
            d[i] += x;
        }
    }
    //配列においてインデックスがi以下の要素d[j]たちの和を計算して返す。
    T sum(int i) {
        T x = 0;
        for (i++; i; i -= i&-i) {
            x += d[i];
        }
        return x;
    }
};

int main(){
  
  long long n;
  cin>>n;
  long long a[n];
  REP(i,n){
    cin>>a[i];
    //cout<<a[i]<<' ';
  }
  //cout<<endl;
  long long all_ms = ((n+1)*n)/2;
  long long l = 0, r = 1'000'000'001;//[l,r):答えとなる中央値の取りうる範囲
  while(r - l > 1){
    //cout<<"iteration"<<endl;
    //cout<<l<<' '<<r<<endl;
    long long x = (l + r)/2;
    long long ta[n];
    REP(i,n){
      if(a[i] >= x){
        ta[i] = 1;
      }else{
        ta[i] = -1;
      }
      //cout<<ta[i]<<' ';
    }
    //cout<<endl;
    long long s[n+1] = {};
    REPP(i,n){
      if(i == 1){
        s[i] = ta[i-1];
      }else{
        s[i] = s[i-1] + ta[i-1];
      }
    }
    long long cnt = 0;
    BIT<long long> tree(2*n+1);
    REP(i,n+1){
      if(i == 0){
        tree.add(s[i] + n);
      }else{
        tree.add(s[i] + n);
        cnt += tree.sum(s[i]+n);
        cnt--;
      }
    }
    long long half = (all_ms + 1)/2;
    //cout<<"count: "<<cnt<<endl;
    if(cnt >= half){
      l = x;
    }else{
      r = x;
    }
  }
  //cout<<"answer: ";
  cout<<l<<endl;
  return 0; 
}