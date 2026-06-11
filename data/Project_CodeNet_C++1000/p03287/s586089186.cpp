// mp.second を li に
#include<iostream>
#include<map>
using namespace std;
#define nC2(n) ((n)*((n)-1)/2)
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
typedef long int li;

int main(){
  int n,m; cin >>n >>m;
  li s=0;
  li ans=0;
  map<int,li> mp; mp[0]=1;
  rep(i,n){
    int a; cin >>a;
    (s+=a)%=m;
    mp[s]++;
  }
  for(auto x: mp){
    ans+=nC2(x.second);
  }
  cout << ans << "\n";
}