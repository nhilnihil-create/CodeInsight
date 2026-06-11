#include<iostream>
#include<string>
#include <vector>
using namespace std;
int main(){
  string S;
  cin >> S;
  int A=S[0]-'0', B=S[1]-'0', C=S[2]-'0', D=S[3]-'0';
  vector<char> v={'+', '-'};
  for(int i=0; i<2; i++){
    for(int j=0; j<2; j++){
      for(int k=0; k<2; k++){
        int sum=A;
        if(i == 0){
          sum += B;
          if(j == 0){
            sum += C;
            if(k == 0){
              sum += D;
            } else{
              sum -= D;
            }
          }else{
            sum -= C;
            if(k == 0){
              sum += D;
            } else{
              sum -= D;
            }            
          }
        }else{
          sum -= B;
                    if(j == 0){
            sum += C;
            if(k == 0){
              sum += D;
            } else{
              sum -= D;
            }
          }else{
            sum -= C;
            if(k == 0){
              sum += D;
            } else{
              sum -= D;
            }            
          }
        }
        if(sum == 7){
          cout << A << v[i] << B << v[j] << C << v[k] << D << "=7" << endl;
          return 0;
        }
      }
    }
  }
}