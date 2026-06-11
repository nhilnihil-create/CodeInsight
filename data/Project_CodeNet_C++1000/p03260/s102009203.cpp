#include <bits/stdc++.h>
using namespace std;

int main(void){
 
 int A,B;
 cin >> A >> B;
 
 if(A*B*1 % 2 == 1 || (A*B*2)&2 == 1 || (A*B*3)%2 == 1){
     cout << "Yes" <<endl;
 }
 else{
     cout << "No" <<endl;
 }
}