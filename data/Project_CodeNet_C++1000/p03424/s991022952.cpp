#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
 for(int i=0; i<N; i++){
   string j;
   cin >> j;
   if(j =="Y"){
     cout << "Four" <<endl;
   break;}
   if(i<N-1){
     continue;}
   else{
     cout << "Three" <<endl;}   
 }
}