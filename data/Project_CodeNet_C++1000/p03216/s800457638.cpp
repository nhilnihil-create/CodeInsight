#include <bits/stdc++.h>
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
using namespace std;

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
  
int main(){
  
  int n;
  cin>>n;
  string s;
  cin>>s;
  int q;
  cin>>q;
  int k[q];
  REP(i,q){
    cin>>k[i];
  }
  long long dsum[n] = {};
  long long msum[n] = {};
  REP(i,n){
    if(i==0){
      if(s[i] == 'D'){
        dsum[i]++;
      }else if(s[i] == 'M'){
        msum[i]++;
      }else{
        ;
      }
    }else{
      if(s[i] == 'D'){
        dsum[i] = dsum[i-1] + 1;
        msum[i] = msum[i-1];
      }else if(s[i] == 'M'){
        dsum[i] = dsum[i-1];
        msum[i] = msum[i-1] + 1;
      }else{
        dsum[i] = dsum[i-1];
        msum[i] = msum[i-1];
      }
    } 
  }
  REP(i,q){
    long long dmnum[n] = {};
    REP(j,k[i]-2){
      if(s[j+1] == 'M'){
        dmnum[j+1] = dmnum[j] + dsum[j];
      }else{
        dmnum[j+1] = dmnum[j];
      }
    }
    for(int j = k[i]-2; j < n-1; j++){
      if(s[j+1] == 'M'){
        if(j-(k[i]-2) >= 1){
          dmnum[j+1] = dmnum[j] + dsum[j] - dsum[j-(k[i]-2)-1];
        }else{
          dmnum[j+1] = dmnum[j] + dsum[j];
        }
      }else{
        dmnum[j+1] = dmnum[j];
      }
      if(s[j-(k[i]-2)] == 'D'){
        dmnum[j+1] -= msum[j+1] - msum[j-(k[i]-2)];
      }else{
        ;
      }
    }
    long long res = 0;
    REP(j,n){
      if(s[j] == 'C'){
        if(j==0)continue;
        res += dmnum[j-1];
      }else{
        continue;
      }
    }
    cout<<res<<endl;
  }
  return 0; 
}