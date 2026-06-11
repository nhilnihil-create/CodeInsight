#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long n;
    cin >> n;
    long long a[n];

    long long minus_cnt = 0;
    long long sum = 0;
    long long abs_min = 1e15;
    for(long long i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] < 0) minus_cnt++;

        sum += abs(a[i]);
        abs_min = min(abs_min, abs(a[i]));
    }

    if(minus_cnt % 2 == 0) cout << sum << endl;
    else cout << sum - 2*abs_min << endl;
    return 0;
    
}