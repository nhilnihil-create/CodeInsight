#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define pa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};

using ll = long long;
using namespace std;
using P = pair<int,int>;
ll mod=1e9+7;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a; }
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; }

int main(){
  int N;
  cin>>N;
  if (N < 1200){
    cout << "ABC" << endl;
  }else if(N < 2800){
    cout << "ARC" << endl;
  }else{
    cout << "AGC" << endl;
  }
  return 0;
}
