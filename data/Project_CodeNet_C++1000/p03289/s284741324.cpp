#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

int main(){
  string s;
  cin>>s;
  bool ja=true;
  if(s[0]!='A') ja=false;
  int C=0;
  for(int i=2;i<s.length()-1;i++){
    if(s[i]=='C') C++;
  }
  if(C!=1) ja=false;
  int cnt=0;
  rep(i,s.length()){
    if(s[i]>='A'&&s[i]<='Z') cnt++;
  }
  if(cnt!=2){
    ja=false;
  }
  if(ja){
    cout<<"AC"<<endl;
    return 0;
  }
  cout<<"WA"<<endl;
}