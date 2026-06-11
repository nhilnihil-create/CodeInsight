#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> C(N-1),S(N-1),F(N-1);
  for(int i=0;i<N-1;i++){
    cin >> C.at(i) >> S.at(i) >> F.at(i);
  }
  for(int i=0;i<N-1;i++){
    int64_t ans=0;
    ans+=S.at(i)+C.at(i);
    for(int j=i+1;j<N-1;j++){
      if(ans<=S.at(j)){
        ans=S.at(j);
      }else{
        if((ans-S.at(j))%F.at(j)!=0){
          ans+=(F.at(j)-((ans-S.at(j))%F.at(j)));
        }
      }
      ans+=C.at(j);
    }
    cout << ans << endl;
  }
  cout << 0 << endl;
  return 0;
}
