#include <bits/stdc++.h>
using namespace std;

int f(int n){
   if(n < 10)  return n;
   return f(n/10) + n%10;
}

int main(void){
    
    int N;
    cin >> N;
    if(N % f(N) == 0) cout << "Yes" << endl;
    else cout << "No" <<endl;
}
