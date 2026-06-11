#include <iostream>
using namespace std;

int N,i,out_point;
int x,H[1100],X,A;        

int main() {
    cin >> N ;
    cin >> X ;
    for (int i = 0; i < N; ++i) cin >> H[i];
 
    int min = H[i],sum = 0;
    
        for (int i = 0; i < N; ++i) {           
         //cout << x << endl;
         if (H[i] <= min) {
           min = H[i]; 
           out_point = H[i];
           }

           sum = sum + H[i];
        }

        X = X - sum;
        X = X / min;
        // for (int i = 0; i < N; ++i) {           
        //  //cout << x << endl;
        //  if (H[i] <= min) {
        //    min = H[i]; 
        //    out_point = H[i];
        //    }

        

    // cout << max << endl;
  // cout << min << endl;
   // max = max - min;
    cout << N + X  << endl;
}