#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> input(2);
  for(int i=0;i<2;i++){
    cin >> input[i];
  }
  
 if((input[0]%500) <= input[1]){
   printf("Yes\n");
 }else{
   printf("No\n");
 }
}