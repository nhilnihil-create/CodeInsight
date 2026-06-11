#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> vec(N);
  for(int i=0; i<N; i++){
    cin >> vec.at(i);
  }
  vector<int> time(25);
  bool end = false;
  for(int i=0; i<N; i++){
    time.at(vec.at(i))++;
    if(time.at(vec.at(i)) > 2){
      end = true;
    } 
  }
  
  int ans = 0;
  
  for(int i=1; i<=24; i++){
    if(end){
      break;
    }
    vector<int> X(25);
    for(int j=0; j<25; j++){
      X.at(j) = time.at(j);
    }
    int T = 0;
    for(int j=0; j<25; j++){
      if(j < T+i && X.at(j) > 0){
        if(X.at(j) > 1 || j >= 12){
          end = true;
        }
        else{
          X.at(24-j)++;
          X.at(j)--;
        }
      }
      if(j >= T+i && X.at(j) > 0){
        if(X.at(j) > 1){
          X.at(24-j)++;
          X.at(j)--;
          if(j >= 12){
            end = true;
          }
        }
        T = j;
      }
    }
    /*for(int n=0; n<24; n++){
      cout << X.at(n) << " ";
    }
    cout << endl;*/
    if(24-T < i){
      end = true;
    }
    if(!end){
      ans = i;
    }
  }
  cout << ans << endl;
}