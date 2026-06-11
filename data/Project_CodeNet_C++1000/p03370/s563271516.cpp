#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int N, X;
    int m;
    cin >> N >> X;
    
    int mm = 1<<30;
    for (int i=0; i < N; i++){
        cin >> m;
        if (mm>m) mm=m;
        X -= m;
    }
    
    cout << N + X / mm << endl;
}