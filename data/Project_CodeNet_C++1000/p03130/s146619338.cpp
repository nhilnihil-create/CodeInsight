#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<int> vec(6);
  for(int i=0; i<6; i++){
    cin >> vec.at(i);
  }
  int c_1 = 0;
  int c_2 = 0;
  int c_3 = 0;
  int c_4 = 0;
  
  for(int j=0; j<6; j++){
    if(vec.at(j) == 1){
      c_1++;
    }
    if(vec.at(j) == 2){
      c_2++;
    }
    if(vec.at(j) == 3){
      c_3++;
    }
    if(vec.at(j) == 4){
      c_4++;
    }
  }
  
  int odd = 0;
  int even = 0;
  if(c_1 == 2){
    even++;
  }
  else{
    odd++;
  }
  if(c_2 == 2){
    even++;
  }
  else{
    odd++;
  }
  if(c_3 == 2){
    even++;
  }
  else{
    odd++;
  }
  if(c_4 == 2){
    even++;
  }
  else{
    odd++;
  }
    
  if(odd == 2 && even == 2){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
    
}