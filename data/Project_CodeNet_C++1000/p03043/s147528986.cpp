#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <iostream>
#include <iomanip>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    long long N, K;
    cin >> N >> K;

    double ans = 0;

    rep(i,N){
        double point = i + 1;
        long long min_count = 0;
        if(point < K){
            min_count = round(ceil(log2(K/point)));
        }
        ans += pow(0.5, min_count);
    }

    cout << fixed << setprecision(10) << ans / N << endl;

    return 0;
}