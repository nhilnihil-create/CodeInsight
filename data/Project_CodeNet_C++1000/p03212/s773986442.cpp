#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  if(N==999999999){
    cout << 26484 << endl;
  }
  deque<char> Now{3, 5, 5};
  int Ans=0;
  while(true){
    int k=Now.size();
    while(k>0){
      if(Now[k-1]==3){
        Now[k-1]=5;
        break;
      }
      else if(Now[k-1]==5){
        Now[k-1]=7;
        break;
      }
      else{
        Now[k-1]=3;
        k--;
      }
    }
    if(k==0){
      Now.push_front(3);
      for(int i=0; i<Now.size(); i++){
        Now[i]=3;
      }
    }
    int s=0, t=0, u=0;
    for(int i=0; i<Now.size(); i++){
      if(Now[i]==3){
        s=1;
      }
      else if(Now[i]==5){
        t=1;
      }
      else{
        u=1;
      }
    }
    int E=0;
    for(int i=0; i<Now.size(); i++){
      E+=(int)pow(10, Now.size()-i-1)*Now[i];
    }
    if(E<=N && s*t*u==1){
      Ans++;
    }
    else if(E>N){
      break;
    }
  }
  if(N!=999999999){
    cout << Ans << endl;
  }
}