#include <bits/stdc++.h>
using namespace std;

int A,B,C,X;
int t = 0;

int main() {
  cin >>A>>B>>C>>X;
  for (int i=0;i<A+1;i++) {
    for (int j=0;j<B+1;j++) {
      for (int s=0;s<C+1;s++) {
        if(500*i+100*j+50*s==X){
          t++;}
    }
    }}
  

   cout<<t<<endl;
}
