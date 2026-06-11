#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long n;
    cin >> n;

    vector<long long> a(n);
    for(long long i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for(long long i = 0; i < n-1; i++){
        if(a[i] + a[i+1] < 0){
            a[i] = -1*a[i];
            a[i+1] = -1*a[i+1];
        }
    }

    long long sum = 0;
    for(long long i = 0; i < n; i++){
        sum += a[i];
    }

    cout << sum << endl;

    return 0;
}