#include<iostream>
#include<string>
using namespace std;

int main(){
  string S; cin >> S;
  int MAX = 0;
  int count = 0;
  for(int i=0;i<S.size();i++){
    if(S.at(i) == 'A' || S.at(i) == 'C' || S.at(i) == 'G' || S.at(i) == 'T' ){
      count++;
      if(MAX < count) MAX = count;
    }else{
      count = 0;
    }
  }
  cout << MAX << endl;
}
