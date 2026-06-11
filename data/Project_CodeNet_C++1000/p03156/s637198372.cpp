#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
signed main(){
  ll n,a,b,pat[3]={};
  cin >> n >> a >> b;
  ll p[n];
  for(int i=0;i<n;i++){
    cin >> p[i];
    if(p[i]<=a){
      pat[0]++;
    }else if(p[i]<=b){
      pat[1]++;
    }else{
      pat[2]++;
    }
  }
  cout << min(pat[0],min(pat[1],pat[2]))<<endl;;
}
