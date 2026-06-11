#include<bits/stdc++.h>
using namespace std;

int main(){
    double N;
    cin >> N;
    vector<double>vec(N);
    double wa = 0;
    for(int i = 0; i < N; i++) {
        cin >> vec[i];
        wa += vec[i];
    }
    wa /=N;
    double a = 777;
    for(int i = 0; i < N; i++) {
        a = min(a,abs(wa-vec[i]));
    }
    for(int i = 0; i < N; i++) {
        if(abs(wa-vec[i]) == a) {
            cout << i << endl;
            return 0;
        }
    }
} 
