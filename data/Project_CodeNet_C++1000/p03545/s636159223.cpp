#include<iostream>
#include<string>

using namespace std;

int main(){
  string s;
  cin >> s;
  string ope[3];
  
  for(int op=0;op < (1<<3);op++){
    int sum = 0;
    sum = s[0] - '0';
    for(int i=0;i < 3;i++){
      if((op >> i) & 1){
        sum += s[i+1] - '0';
        ope[i] = '+';
      }else{
        sum -= s[i+1] - '0';
        ope[i] = '-';
      }
    }
    if(sum == 7) break;
  }
  cout << s[0] << ope[0] << s[1] << ope[1] << s[2];
  cout << ope[2] << s[3] << "=7" << endl;
  return 0;
}