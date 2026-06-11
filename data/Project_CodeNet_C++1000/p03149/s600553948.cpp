#include <bits/stdc++.h>
#define P pair<long long, long long>

using namespace std;
const int INF=1e5;

int main(){
  int n[5], ref[5]={1,4,7,9};
  for(int i=0;i<4;i++)cin >> n[i];
  sort(n, n+4);
  for(int i=0;i<4;i++){
    if(n[i]!=ref[i]){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}

