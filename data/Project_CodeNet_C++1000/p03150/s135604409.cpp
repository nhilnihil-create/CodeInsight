#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
 


int main(){
 string s;
  string target="keyence";
  cin >>s;
  int n=s.size();
  bool a=false;
  int cnnt=0;
  if(s==target)a=true;
  rep(i,n){
    for(int j=i; j<n; j++){
      string S="";
      for(int k=0;k<n;k++){
        if(i<=k && k<=j)continue;
        else{
          S.push_back(s.at(k));
        }
      }
      if(S==target){
        a=true;
        break;
      }
    }
    if(a)break;
  }
  
        
  if(a) cout <<"YES" << endl;
  else cout << "NO" <<endl;
}