#include<bits/stdc++.h>
using namespace std;

int main(){
  string S,A;
  cin >> S;
  vector<int> s(4);
  for(int i=0;i<4;i++){
    s.at(i) = S.at(i) - '0';
  }
  
  for(int tmp=0;tmp < (1 << 3);tmp++){
    bitset<3> p(tmp);
    int sum=s.at(0);
    
    for(int i=0;i<3;i++){
      if(p.test(i)){
        sum += s.at(i+1);
      }else{
        sum -= s.at(i+1);
      }
    }
    
    if(sum == 7){
      A += to_string(s.at(0));
      for(int i=0;i<3;i++){
        if(p.test(i)){
          A += '+';
        }else{
          A += '-';
        }
        A += to_string(s.at(i+1));
      }
      A += "=7";
      break;
    }
  }
  cout << A << endl;
}
    
