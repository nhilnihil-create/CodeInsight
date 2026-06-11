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
  int N;
  cin>>N;
  set<string>k;
  for(int i=0;i<N;i++){
    string w;
    cin>>w;
    char a,b;
    b=w[0];
    int n=w.size();
    if(i>0&&a!=b){cout<<"No"<<endl;return 0;}
    if(k.count(w)){cout<<"No"<<endl;return 0;}
    a=w[n-1];
    k.insert(w);
  }
  cout<<"Yes"<<endl;
  return 0;
}