#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<n; i++) 

int main() {
    long long int n, k;
    cin >> n >> k;

    long long int cnt = 0;

    if(k%2==0){
        long long int m = n / k;
        cnt += m * m * m;
        m = (n + k / 2) / k ;
        cnt += m * m * m;
    }else{
        long long int m = n / k;
        cnt += m * m * m;
    }
    cout << cnt << endl;
}