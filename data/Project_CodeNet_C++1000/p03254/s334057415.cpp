#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long n, x;
    cin >> n >> x;
    vector<long long> a(n);

    for(long long i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long count = 0;
    for(long long i = 0; i < n; i++){
        if(i == n-1){
            if(x == a[i]){
                count++;
            }
            continue;
        }

        if(a[i] <= x){
            x -= a[i];
            count++;
        }
    }
    cout << count << endl;
    return 0;
}