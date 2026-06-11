#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> b(N),ans(N),index(N);
  for(int i=0;i<N;i++){
    cin >> b.at(i);
    index.at(i)=i;
  }
  for(int i=N-1;i>=0;i--){
    if(index.size()<b.at(i)){
      cout << -1 << endl;
      return 0;
    }
    ans.at(index.at(b.at(i)-1))=b.at(i);
    index.erase(index.begin()+b.at(i)-1);
  }
  for(int i=0;i<N;i++){
    cout << ans.at(i) << endl;
  }
  return 0;
}
