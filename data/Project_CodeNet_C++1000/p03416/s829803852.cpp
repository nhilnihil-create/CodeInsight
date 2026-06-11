#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B;
  cin >> A >>B;
  int N;
  int S=0;
  
  N = A;
  while (N <= B){
  	int a,b,c,d,e;
    a = N % 10;
    b = (N % 100 - N % 10) / 10;
    c = (N % 1000 - N % 100) / 100;
    d = (N % 10000 - N % 1000) / 1000;
    e = (N % 100000 - N % 10000) / 10000;
    
    if (a==e && b==d){
    	S ++;
    }
    
    N +=1;
  }
  
  cout << S;
}




