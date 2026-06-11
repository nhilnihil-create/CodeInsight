#include <bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(long long i=a; i<b; i+=1)
#define repr(i,a,b) for(long long i=a; i<=b; i+=1)
#define vec vector<ll>
#define pb push_back
#define sort(a) sort(a.begin(),a.end())
#define reverse(a) reverse(a.begin(),a.end())

using namespace std;
int main() {
  ll N,M;
  cin>>N>>M;
  if(N>=2 && M>=2) {
  ll A=(N-2)*(M-2);
  cout<<A<<endl;
  }
  if(N==1 && M==1)
    cout<<"1"<<endl;
  else if(N==1 || M==1) {
    cout<<max(N,M)-2<<endl;
  }
}
