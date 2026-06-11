#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    long long n, t, a;
    cin >> n >> t >> a;

    long long h[n];
    for(long long i = 0; i < n; i++){
        cin >> h[i];
    }

    long double dif_min = 1e9;
    long long index_min;

    for(long long i = 0; i < n; i++){
        long double temp = (long double)t - (long double)h[i]*0.006;
        if(abs(a-temp) < dif_min){
            dif_min = abs(a-temp);
            index_min = i;
        }
    }

    cout << index_min + 1 << endl;
    return 0;

}