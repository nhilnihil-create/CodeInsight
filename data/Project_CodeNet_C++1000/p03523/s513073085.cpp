#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
vector<pair<int64_t,int64_t>>prime_factorize(int64_t x){
  vector<pair<int64_t,int64_t>>p;
  for(int64_t i=2;i*i<=x;i++){
    int cnt=0;
    if(x%i==0){
    while(x%i==0){cnt++;x/=i;}
    p.push_back(make_pair(i,cnt));
    }
  }
  if(x!=1){p.push_back(make_pair(x,1));}
  return p; 
}

int main() {
  string s;
  cin>>s;
  for(int p=0;p<(1<<4);p++){
    vector<int> a(4);
    for(int i=0;i<4;i++){
      if((p>>i)&1){a[i]=1;}
    }
    string g;
    if(a[0]){g.push_back('A');}
    g+="KIH";
    if(a[1]){g.push_back('A');}
    g.push_back('B');
    if(a[2]){g.push_back('A');}
    g.push_back('R');
    if(a[3]){g.push_back('A');}

    if(s==g){cout<<"YES"<<endl;return 0;}
  }
  cout<<"NO"<<endl;
  return 0;
}