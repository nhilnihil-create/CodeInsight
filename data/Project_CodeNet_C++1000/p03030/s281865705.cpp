#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;


int main(){
  int n;
  cin>>n;
  vector<tuple<string,int,int>> v(n) ;
  rep(i,n){
    string a; int b;
    cin>>a>>b;
    v.at(i)=make_tuple(a,100-b,i+1);
  }

  sort(v.begin(), v.end()) ;
  rep(i,n){
    string a; int b,x;
    tie(a,b,x)=v.at(i);
    cout<<x<<endl;
  }
  return 0;
}