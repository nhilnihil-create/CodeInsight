#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main(){
    
   int N,K; cin >> N >> K;
   cout << (((N-K) + (K-2))/(K-1)) + 1 << endl;
}