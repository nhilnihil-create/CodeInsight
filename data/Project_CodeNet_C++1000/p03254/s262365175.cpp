#include <iostream>
#include <string>
#include <algorithm>
// #include <vector>
// #include <algorithm>
// #include <cmath>
// #include <math.h>
using namespace std;

int main(){
    int N, X;
    cin >> N >> X;
    int a[N];
    for (int i=0; i<N; i++) cin >> a[i];
    sort(a, a + N);
    
    int res = 0;
    for (int i=0; i<N; i++){
        
        if (X >= a[i]){
            ++res;
            X -= a[i];
        } else {
            break;
        }
    } 
    if (N == res && X){
        --res;
    }
    
    cout << res << endl;
}