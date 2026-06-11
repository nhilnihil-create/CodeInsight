#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int64_t L0 = 2;
    int64_t L1 = 1;
    for (int i=0;i<N-1;i++){
        int64_t L2 = L1 + L0;
        L0 = L1;
        L1 = L2;
    }
    cout << L1 << endl;
}