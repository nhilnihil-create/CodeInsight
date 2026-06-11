#include <bits/stdc++.h>
using namespace std;
int main(){
 
 int N;
 cin >> N;
 int A,B;
 cin >> A >> B;
 vector<int>P(N);
 for(int i=0; i<N; i++){
  cin >> P.at(i);
 }
 int AP = 0;
 int BP = 0;
 int CP = 0;
 
 for(int i=0; i<N; i++){
 if(P.at(i)<=A){
  AP += 1;
 }
 else if(A < P.at(i) && P.at(i)<=B){
  BP += 1;
 }
 else if(B < P.at(i)){
  CP += 1;
 } 
}

int big = min(AP,min(BP,CP));
 cout << big << endl;
}