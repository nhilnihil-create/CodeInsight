#include <bits/stdc++.h>
using namespace std;

int digit_sum(int n){
   if(n < 10)  return n;
   return digit_sum(n/10) + n%10;
}

int main(void){
   
    int N,A,B,sum = 0;
    cin >> N >> A >> B;
    
    for(int i=1;i<=N;i++){
        int k = digit_sum(i);
        if(A <= k && k <= B) sum += i;
    }
    
    cout << sum <<endl;
}
