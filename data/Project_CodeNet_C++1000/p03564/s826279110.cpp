#include <bits/stdc++.h>
using namespace std;
         
int main() {
          int N, K, sum = 1;
          cin >> N >> K;
          for (int i; i < N; i++){
            if (sum <= K)
              sum *= 2;
            else
              sum += K;
          }
          cout << sum << endl;
        }