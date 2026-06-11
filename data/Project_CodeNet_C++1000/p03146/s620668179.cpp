#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int s;
  cin>>s;
  set<int> a;
  a.insert(s);
  int i=2;
  while(true){
    if(s%2==0){
      s=s/2;
    }
    else{
      s=s*3+1;
    }
    if(a.count(s)){
      break;
    }
    else{
      a.insert(s);
      i++;
    }
  }
  cout<<i<<endl;
}