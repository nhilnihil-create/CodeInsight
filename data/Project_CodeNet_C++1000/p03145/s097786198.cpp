#include <bits/stdc++.h>
using namespace std;

int main(void){
   
 int data[3];
 for(int i=0;i<3;i++){
     cin >> data[i];
 }
 
 sort(data,data+3);
 
 cout << data[0] * data[1] /2 <<endl;
}