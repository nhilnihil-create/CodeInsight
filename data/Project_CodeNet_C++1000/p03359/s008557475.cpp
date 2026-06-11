#include<bits/stdc++.h>
#define lint long long int
#define rep(i,n) for(int i=0;i<int(n);i++)
#define arep(i,a,n) for(int i=a;i<n;i++)
#define sort(a) sort(a.begin(),a.end())
#define reverse(a) reverse(a.begin(),a.end())
#define fill(a,x) fill(a.begin(),a.end(),x)
#define pb push_back
using namespace std;

template<typename T>T gcd( T a,T b){if(b==0)return a;return gcd(b,a%b);}
template<typename T>T lcm(T a, T b){return a * b / gcd(a, b);}
template<typename T>void out(T data){cout<<data<<endl;}

int main(){
  int a,b;
  cin>>a>>b;
  if(a<=b){
    out(a);
  }else{
    out(a-1);
  }
  return 0;
}
