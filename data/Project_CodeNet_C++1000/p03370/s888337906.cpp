#include <bits/stdc++.h>
using namespace std;
int main() {
 int N, X;
 cin >> N >> X;
 
 vector<int> A(N);
 int i=0;
 int count =0;
 while (i<N){
   cin >> A.at(i);
   count += A.at(i);
   i++;
 }
 
 sort(A.begin(), A.end());
 int j = (X - count)/A.at(0);
 
 cout << N + j << endl;


}