#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  if (N<=5){
    vector<int> ans = {2,5,63,20,30};
    for (int i=0; i<N-1; i++) cout << ans[i] << ' ';
    cout << ans[N-1] << endl;
    return 0;
  }
  int S=0;
  set<int> ans;
  for (int i=1; i<=N; i++){
    if (i%4==1){
      ans.insert((i/4)*6+2);
      S += (i/4)*6+2;
    }
    else if (i%4==2){
      ans.insert((i/4)*6+3);
      S += (i/4)*6+3;
    }
    else if (i%4==3){
      ans.insert((i/4)*6+4);
      S += (i/4)*6+4;
    }
    else{
      ans.insert((i/4)*6);
      S += (i/4)*6;
    }
  }
  if (S%6==2){
    ans.erase(8);
    if (ans.find((N/4)*6) == ans.end()) ans.insert((N/4)*6);
    else ans.insert((N/4+1)*6);
  }
  else if (S%6==5){
    ans.erase(9);
    if (ans.find((N/4)*6+4) == ans.end()) ans.insert((N/4)*6+4);
    else ans.insert((N/4+1)*6);
  }
  else if (S%6==3){
    ans.erase(9);
    ans.insert((N/4)*6);
    if (ans.find((N/4)*6) == ans.end()) ans.insert((N/4)*6);
    else ans.insert((N/4+1)*6);
  }
  for (int i: ans){
    if (i!=2) cout << ' ';
    cout << i;
  }
  cout << endl;
}
