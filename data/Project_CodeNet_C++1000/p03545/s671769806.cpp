#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int My_Calc(int A,int B,int index){
    
    if(index == 0) return A+B;
    else return A-B;
}
bool My_Calc_All(int i,int j,int k,int A,int B,int C,int D){
    
    char s[2]; s[0] = '+'; s[1] = '-';
    int sum = 0;
    sum += My_Calc(A,B,i);
    sum += My_Calc(0,C,j);
    sum += My_Calc(0,D,k);
    
    if(sum == 7) { cout << A << s[i] << B << s[j] << C << s[k] << D << "=" << sum << endl; return true; }
    else { return false; }
}
int main(){
  
  string s; cin >> s;
  int A = s[0] - 48;
  int B = s[1] - 48;
  int C = s[2] - 48;
  int D = s[3] - 48;
  
  for(int i=0;i<2;i++){
      for(int j=0;j<2;j++){
          for(int k=0;k<2;k++){
              if(My_Calc_All(i,j,k,A,B,C,D)) return 0;
          }
      }
  }
} 