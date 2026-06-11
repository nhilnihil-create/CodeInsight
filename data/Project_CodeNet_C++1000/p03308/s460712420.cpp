#include <iostream>
using namespace std;

int N;
long long A[110];         // 最大 200 個なので余裕を持って 210 に --- 200 以上ならなんでもよいです

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];

    long long min = A[0],max = A[0];

    // 操作が行える限り操作を繰り返す
        for (int i = 0; i < N; ++i) {
          // cout <<  A[i] << endl;
 
           
         if (A[i] >= max) max = A[i];  // 奇数があったらフラグを立てる
         if (A[i] <= min) min = A[i];  // 奇数があったらフラグを立てる
        
        
        }

    // cout << max << endl;
    // cout << min << endl;
   // max = max - min;
    cout << max - min << endl;
}