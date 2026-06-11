#include <bits/stdc++.h>
using namespace std;

int main(){
  string str1;
  cin >> str1;
  
  int  n = stoi(str1);
  int  L = n / 100;
  int  R = n % 100;
   

 if(1<=L&&L<=12){
    if(1<=R&&R<=12)printf("AMBIGUOUS\n");
    else printf("MMYY\n");
  }else{
    if(1<=R&&R<=12)printf("YYMM\n");
    else printf("NA\n");
  }
}