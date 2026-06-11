#include<bits/stdc++.h>
using namespace std;

int main(){
    double N;
    cin >> N;
    vector<double>a(N);
    double goukei = 0.0;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        goukei+=a[i];
    }
    goukei/=N;
    double sa = 100;
    for(int i = 0; i < N; i++) {
        sa = min(sa,abs(goukei-a[i]));
    }
    for(int i = 0; i < N; i++) {
        if(abs(goukei-a[i]) == sa) {
            cout << i << endl;
            return 0;
        }
    }
} 
