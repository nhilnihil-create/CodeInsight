#include <bits/stdc++.h>
using namespace std;
using ll = long long; // ll は long long　と同じとする。(int64_t)
int main(){
    int N;
    cin >> N;
    int all = 1;
    int count = 1;
    int A[N];
    for(int i = 0; i < N; i++){
       cin >> A[i];
       all *= 3;
       if(A[i] % 2 == 0){
           count*=2;
       }
    }
   cout << all - count << endl; 
}