#include <bits/stdc++.h>

using namespace std;
/*
float abs(float x) {
    if(x < 0) return -1*x;
    else{return x;}
}*/

int main() {
    int N, T, A;
    cin >> N >> T >> A;
    int H;
    int ind = 0; double min = 10000000;
    for(int i = 0; i < N; ++i) {
        cin >> H;
        double temp = (float(T)-float(H)*0.006);
        if(abs(double(A)-temp) < min) {
            ind = i+1;
            min = abs(double(A)-temp);
            //cout << i << " " << min << endl;
        }
    }
    cout << ind;
}