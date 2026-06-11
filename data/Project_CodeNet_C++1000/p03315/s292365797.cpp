#include<bits/stdc++.h>

#define ll long long
const int inf = 1e9+7;
const ll INF = 1e18+7;

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin>>s;
  int i = 0;
  for(int x :s){
    if(x == '+')
      ++i;
    else
      --i;
  }
  cout<<i<<"\n";
}
