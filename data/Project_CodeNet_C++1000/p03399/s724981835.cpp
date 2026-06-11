#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int bus_min = min(A,B);
    int train_min= min(C,D);

    cout << bus_min + train_min << endl;
}