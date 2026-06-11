#include <bits/stdc++.h>
using namespace std;

int main(){

  int N;
  cin >> N;
  vector<string> S(N);
  for(int i=0; i<N; i++){
    cin >> S.at(i);
  }
  
  int M;
  cin >> M;
  vector<string> T(M);
  for(int i=0; i<M; i++){
    cin >> T.at(i);
  }
  
  map<string,int> card;
  for(string x:S){
    if(card.count(x)){
      card.at(x)++;
    }
    else{
      card[x]=1;
    }
  }
  
  for(string x:T){
    if(card.count(x)){
      card.at(x)--;
    }
    else{
      card[x]=-1;
    }
  }
  
  int max_card = 0;
  for(string x:S){
    if(max_card < card.at(x)){
      max_card = card.at(x);
    }
  }

  cout << max_card << endl;
  
}