#include<bits/stdc++.h>

#define ll long long
const int inf = 1e9+7;
const ll INF = 1e18+7;

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin>>n;
  int s = 0;
  for(int i = 0; i < n; ++i){
    int tmp;
    cin >> tmp;
    while((tmp&1) == 0){
      ++s;
      tmp /=2;
    }
  }
  cout<<s<<"\n";
}
