#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string s,ans="WA";
  cin>>s;
  map<string,int> cnt;
  if(s[0]=='A'){
    for(int i=2; i<s.size()-1; i++){
      if(s[i]=='C'){
        cnt["C"]++;
      }
    }
    if(cnt["C"]==1){
      int A=0;
      rep(j,s.size()){
        int p=s[j];
        if(65<=p&&p<=90){
          A++;
        }
      }
      if(A==2){
        ans="AC";
      }
    }
  }
  cout<<ans<<endl;
}