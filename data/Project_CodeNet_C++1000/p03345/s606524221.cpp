#include <bits/stdc++.h>
using namespace std;
int main() {
     long long int A,B,C,K;
     cin >> A >> B >> C >> K;
     long long int ans = A-B;
     if(K%2==1){
          ans*=-1;
     }
     // if(K==0){
     //      ans*=1;
     // }
     if(ans>100000000000000000){
          cout << "Unfair";
     }
     else{
          cout << ans;
     }
}