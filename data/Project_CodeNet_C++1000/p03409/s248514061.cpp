#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define P pair<int,int>

const long long MOD = 1000000007;

int main(){
  int n,k;
  int ans=0,my=0;
  cin >> n;
  vector<P> a(n),b(n);
  vector<bool> aa(n,true);

  rep(i,n) cin >> a.at(i).first >> a.at(i).second;
  rep(i,n) cin >> b.at(i).first >> b.at(i).second;
 
  sort(b.begin(),b.end());
  
  rep(i,n){
    my=-1;
    k=-1;
    rep(j,n){
      if(aa.at(j)){
        if(a.at(j).first < b.at(i).first && a.at(j).second < b.at(i).second){
          if(a.at(j).second > my){ 
            my=a.at(j).second;
            k=j;
          }
        }
      }
    }
    if(k!=-1){
      aa.at(k)=false;
      ans++;
    }
  }
  cout << ans << endl;
}