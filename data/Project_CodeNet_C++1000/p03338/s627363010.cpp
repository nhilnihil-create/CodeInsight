#include<bits/stdc++.h>

using namespace std;

int main(){

  //最大値
  int maxvalu = 0;

  int N;
  cin >> N;
  string S;

  cin >> S;

  for(int i = 1; i < N; i++){
    int counter = 0;
    set<char> bef;//前半
    set<char> aft;//後半

    for(int j = 0; j < N; j++){
      if(j < i){
        bef.insert(S.at(j));
      }
      else{
        aft.insert(S.at(j));
      }
    }
    for(auto a : bef){
      if(aft.count(a)){
        counter++;
      }
    }

    if(maxvalu < counter){
      maxvalu = counter;
    }
  }

  cout << maxvalu << endl;
}
