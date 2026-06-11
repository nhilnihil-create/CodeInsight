#include <bits/stdc++.h>
using namespace std;

int main(){
    long long r, D, x;
    cin >> r >> D >> x;
    vector<long long> ans(10);
    
    for(int i=0; i<10; i++) {
        if( i == 0 ) ans[0] = r*x - D;
        else  ans[i] = r*ans[i-1] - D;
    }

    for(int i =0; i<10; i++) {
        cout << ans[i] << endl;
    }
}