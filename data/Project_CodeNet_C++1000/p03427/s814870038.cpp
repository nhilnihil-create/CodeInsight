#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

int main(){
  string n;
  cin>>n;
  bool ja=true;
  for(int i=1;i<len(n);i++){
    if(n[i]!='9') ja=false;
  }
  if(ja){
    cout<<(len(n)-1)*9+n[0]-'0'<<endl;
    return 0;
  }
  cout<<(len(n)-1)*9+n[0]-'0'-1<<endl;
}