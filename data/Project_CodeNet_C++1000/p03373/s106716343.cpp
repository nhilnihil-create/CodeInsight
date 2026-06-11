#include<iostream>
using namespace std;
int main(){
  int A_val = 0;
  int B_val = 0;
  int AB_val = 0;
  int A_num = 0;
  int B_num = 0;
  cin >> A_val >> B_val >> AB_val >> A_num >> B_num;
  int result = -1;
  int current_A_num = 0;
  int current_B_num = 0;
  int current_AB_num = 0;
  int AB_num = 2*max(A_num, B_num);
  
  for(int i=0; i<=AB_num; i++){
    current_AB_num = i;
    current_A_num = A_num - current_AB_num/2;
    if(current_A_num < 0) current_A_num = 0;
    current_B_num = B_num - current_AB_num/2;
    if(current_B_num < 0) current_B_num = 0;
    if(result < 0) result = current_A_num * A_val + current_B_num * B_val + current_AB_num * AB_val;
    result = min(result, current_A_num * A_val + current_B_num * B_val + current_AB_num * AB_val);    
  }
  cout << result << endl;
  return 0;
}