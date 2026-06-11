#include<bits/stdc++.h>
using namespace std;

int main(){
int a,count_1,count_2,count_3,count_4;
bool A = true;
  count_1=0;
  count_2=0;
  count_3=0;
  count_4=0;
  for(int i =0; i<6;i++){
  cin >>a;
  if(a==1){
  count_1++;
  }
  else if(a==2){
  count_2++;
  }
  else if(a==3){
  count_3++;
  }
  else if(a==4){
  count_4++;
  }
  }
  
 if(count_1==3 || count_2==3 || count_3==3 || count_4==3){
 A = false;
 }
 if(A==true){
 cout << "YES" <<endl;
 }
 if(A==false){
 cout << "NO"<<endl;
 }
}
