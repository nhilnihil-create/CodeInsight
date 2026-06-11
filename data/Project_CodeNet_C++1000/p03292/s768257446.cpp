#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main(void){
    
    int A[3];
    for(int i = 0; i < 3; i++){
        cin >> A[i];
    }
    
    sort(A, A+3);
    int ans = abs(A[0] - A[2]);
    cout << ans << endl;
}
