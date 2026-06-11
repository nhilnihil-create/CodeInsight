#include <iostream>
using namespace std;

int N,i,out_point;
double x,H[1100],T,A;        

int main() {
    cin >> N;
    cin >> T >> A;
    for (int i = 0; i < N; ++i) cin >> H[i];
 
    double min;
    
    // 操作が行える限り操作を繰り返す
        for (int i = 0; i < N; ++i) {
        //cout <<  H[i] << endl;
 
         x = T - H[i] * 0.006;
        //cout << x << endl;
         
        if (x < A) x = A - x;
        else x = x - A;
          
         //cout << x << endl;

         if (x <= min || i == 0) {
           min = x; 
           out_point = i;
           }
            // 奇数があったらフラグを立てる
        
        
        }

    // cout << max << endl;
   //  cout << min << endl;
   // max = max - min;
    cout << out_point +1 << endl;
}