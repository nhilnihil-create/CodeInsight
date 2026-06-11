#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    int sum =0;
    rep(i,N){
        cin >> a.at(i);
        sum += a.at(i);
        a.at(i) *= N;
    }

    int mn = 100*N;
    int ix = 100;
    rep(i,N){
        if(abs(a.at(N-1-i)-sum) <= mn){
            mn = abs(a.at(N-1-i)-sum);
            ix = N-1-i;
        }
    }
    cout << ix << endl;
}   