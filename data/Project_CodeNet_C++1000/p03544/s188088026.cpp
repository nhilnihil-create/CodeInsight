#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    if (N == 0){
        cout << 2 <<endl;
        return 0;
    }else if (N == 1){
        cout << 1 << endl;
        return 0;
    }

    int64_t t0 = 2;
    int64_t t1 = 1;
    int64_t t2;

    for (int i; i < N - 1; i++){
        t2 = t0 + t1;
        t0 = t1;
        t1 = t2;
    }

    cout << t2 << endl;

}