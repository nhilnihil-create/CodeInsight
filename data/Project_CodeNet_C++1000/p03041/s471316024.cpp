#include<iostream>
#include<string>
 
using namespace std;

char tolow(char s){
    return(s+0x20);
  }

int main(){
  int N,K;
  string S;
  cin >> N;
  cin >> K;
  cin >> S;
  
  S[K-1]=tolow(S[K-1]);
  cout << S;
}