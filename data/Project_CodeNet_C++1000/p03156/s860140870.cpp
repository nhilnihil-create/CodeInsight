#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,A,B;
  cin >> N >> A >> B;
  vector<int> cnt(3,0);
  for(int i=0;i<N;i++){
    int p;
    cin >> p;
    if(p<=A)  cnt.at(0)++;
    else if(p<=B) cnt.at(1)++;
    else  cnt.at(2)++;
  }

  int ans=1e9;
  for(int i=0;i<3;i++)  ans=min(ans,cnt.at(i));
  cout << ans << endl;

  return 0;
}