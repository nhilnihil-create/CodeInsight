#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll=long long;

int main(){
  int n,Alice_point=0,Bob_point=0;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  rep(i,n){
    if(i%2==0) Alice_point += a[i];
    if(i%2==1) Bob_point += a[i];
  }
  cout << Alice_point-Bob_point << endl;
}
  
  