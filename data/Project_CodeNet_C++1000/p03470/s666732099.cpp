#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int N,sum;
    int mochi[101] = {};
    sum = 0;

    cin >> N;

    rep(i,N){
        int a;
        cin >> a;
        mochi[a] = 1;
    }
    rep(i,101){
        sum += mochi[i];
    }
    cout << sum << endl;

}