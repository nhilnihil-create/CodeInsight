#include<bits/stdc++.h>
using namespace std;

int main(void){
  int N=0, M=0;
  cin >> N;
  vector<string> s(N);
  for(int i=0;i<N;i++){
    cin >> s.at(i);
  }
  
  cin >> M;
  vector<string> t(M);
  for(int i=0;i<M;i++){
    cin >> t.at(i);
  }
  vector<int> sum(N);
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(s.at(i)==s.at(j)){
        sum.at(i)++;
      }//if
    }//for j
    for(int j=0;j<M;j++){
      if(s.at(i)==t.at(j)){
        sum.at(i)--;
      }
    }
   }//for i

  int max_sum=sum.at(0);
  for(int i=0;i<N;i++){
    if(max_sum < sum.at(i)){
      max_sum=sum.at(i);
    }
  }
  
  if(max_sum<=0){
    cout << 0 << endl;
  }else{
    cout << max_sum << endl;
  }
  
}