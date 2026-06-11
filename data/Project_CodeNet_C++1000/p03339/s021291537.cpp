#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin>>n;
  int ruiE[300005],ruiW[300005];
  ruiE[0]=0;ruiW[0]=0;
  string s;
  cin>>s;
  rep(i,n){
    if(s[i]=='W'){
      ruiW[i+1]=ruiW[i]+1;
      ruiE[i+1]=ruiE[i];
    }else{
      ruiE[i+1]=ruiE[i]+1;
      ruiW[i+1]=ruiW[i];
    }
  }
  int min_chng=900010;
  rep(i,n){
    int chng;
    chng=ruiW[i]+(ruiE[n]-ruiE[i+1]); 
    min_chng=min(min_chng,chng);
  }
  cout<<min_chng<<endl;
}