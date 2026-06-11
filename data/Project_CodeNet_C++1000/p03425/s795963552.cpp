#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;cin>>N;
  vector<set<string>>B(5);
  for(int i=0;i<N;i++){
    string T;
    cin>>T;
    if(T.at(0)=='M'){
      B[0].insert(T);
    }
    if(T.at(0)=='A'){
      B[1].insert(T);
    }
    if(T.at(0)=='R'){
      B[2].insert(T);
    }
    if(T.at(0)=='C'){
      B[3].insert(T);
    }
    if(T.at(0)=='H'){
      B[4].insert(T);
    }
  }
  vector<long long>S(5);
  for(int i=0;i<5;i++){
    S[i]=B[i].size();
  }
  long long Ans=0;
  for(int tmp=0;tmp<(1<<5);tmp++){
    bitset<5>E(tmp);
    int s=0;
    for(int i=0;i<5;i++){
      if(E.test(i)){
        s++;
      }
    }
    if(s==3){
      long long K=1;
      for(int i=0;i<5;i++){
        if(E.test(i)){
          K=K*S[i];
        }
      }
      Ans+=K;
    }
  }
  cout<<Ans<<endl;
}
    
