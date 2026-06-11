#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;

  vector<string> data(N);
  for(int i=0; i<N; i++){
    cin >> data.at(i);
  }

  int NfootA= 0;
  int NheadB= 0;
  int Nchimera= 0;
  int cnt_intra= 0;
  for(auto word:data){
    if(word.back()=='A' && word.at(0)=='B'){
      Nchimera++;
    }
    else if(word.back()=='A'){
      NfootA++;
    }
    else if(word.at(0)=='B'){
      NheadB++;
    }

    for(size_t i=0; i< word.size()- 2; i++){
      if(word.substr(i,2)=="AB"){
        cnt_intra++;
      }
    }
  }

  int cnt_inter= 0;
  if(Nchimera > 0){
    cnt_inter+= Nchimera- 1;
    if(NfootA > 0){
      cnt_inter++;
      NfootA--;
    }
    if(NheadB > 0){
      cnt_inter++;
      NheadB--;
    }
  }
  
  cnt_inter+= min(NfootA, NheadB);

  int ans= cnt_intra+ cnt_inter;

  cout << ans << endl;
}