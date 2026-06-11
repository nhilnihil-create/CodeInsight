#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<string> S(N);
  vector<int> P(N),out(N);
  for(int i=0;i<N;i++){
    out.at(i) = i + 1;
    cin >> S.at(i) >> P.at(i);
  }
  for(int j=0;j<N-1;j++){
    for(int i=0;i<N-1;i++){
      if(S.at(i) > S.at(i+1)){
        swap(S.at(i),S.at(i+1));
        swap(P.at(i),P.at(i+1));
        swap(out.at(i),out.at(i+1));
      }
    }
  }
   for(int j=0;j<N-1;j++){
    for(int i=0;i<N-1;i++){
      if(P.at(i) < P.at(i+1)&&S.at(i)==S.at(i+1)){
        swap(S.at(i),S.at(i+1));
        swap(P.at(i),P.at(i+1));
        swap(out.at(i),out.at(i+1));
      }
    }
   }
      for(int i=0;i<N;i++)printf("%d\n",out.at(i));
  return 0;
}