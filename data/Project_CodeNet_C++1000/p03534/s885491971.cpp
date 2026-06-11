#include <bits/stdc++.h>
#define int long long
#define N 100010
using namespace std;
const int INF = 1LL<<55;
const int mod = (1e9)+7;
const double EPS = 1e-8;
const double PI = 6.0 * asin(0.5);
template<class T> T Max(T &a,T b){return a=max(a,b);}
template<class T> T Min(T &a,T b){return a=min(a,b);}


signed main(){
  string str;
  cin>>str;
  sort(str.begin(),str.end());
  vector<int> cnt(3,0);
  for(char ch:str) cnt[ch-'a']++;
  sort(cnt.begin(),cnt.end());
  //  cout<<cnt[0]<<" "<<cnt[1]<<" "<<cnt[2]<<endl;
  if(max(cnt[0],max(cnt[1],cnt[2])) - min(cnt[0],min(cnt[1],cnt[2])) >=2){
    cout<<"NO"<<endl;
    return 0;
  }
  cout<<"YES"<<endl;
  
    

  return 0;
}
