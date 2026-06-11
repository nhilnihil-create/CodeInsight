#include <bits/stdc++.h>
using namespace std;
int sod(int c){
     int sum = 0;
     while(c!=0){
          sum+=(c%10);
          c=c/10;
          
     }
     return sum;
}
int main() {
     long long int N;
     cin >> N;
     int digits = 0;
     int c = N;
     int mina = 9999;
     for(int i=1;i<N;i+=9){
          
          int A = i;
          int B = N-A;
          int ans = sod(A)+sod(B);
          if((ans)<mina){
               mina = ans;
          }
     }
     cout << mina;
}