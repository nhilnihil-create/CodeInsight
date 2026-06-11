#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
ll mod= 1e9 + 7;


int main(){
  int n,q;
  cin >> n>>q;
  int sub[n];//0-index
  sub[0]=0;
  string s;
  cin >>s;
  for(int i=1;i<n;i++){
    if(s[i-1]=='A' && s[i]=='C'){sub[i]=sub[i-1]+1;}else{sub[i]=sub[i-1];}
  }
  rep(i,q){
    int l,r;
    cin >> l >>r;
    cout << sub[r-1]-sub[l-1] << endl;
  }
}