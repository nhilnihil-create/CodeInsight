#include<iostream>
using namespace std;
int main(){
  int n[5],k,hantei=0;
  for(int i=0;i<5;i++){
      cin >> n[i];
  } 
  cin >> k;
  for(int i=0;i<5;i++){
      for(int j=i+1;j<5;j++){
          if(n[j]-n[i] > k){
              hantei = 1;
              break;
          }
      }
  }
  if(hantei == 0) cout << "Yay!" << endl;
  else cout << ":(" << endl;
}