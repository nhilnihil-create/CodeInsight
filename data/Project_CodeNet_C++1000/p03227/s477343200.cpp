// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
signed main(){
  string s;
  cin >> s;
  if(s.size()%2!=0){
    reverse(s.begin(),s.end());
  }
  cout << s<<endl;
}
