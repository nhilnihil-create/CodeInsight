#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;



int main(){
    long long n;
    cin >> n;

    long long ans = 0;
    vector<long long> ab(n);

    for(long long i = 0; i < n; i++){
        long long a, b;
        cin >> a >> b;
        ans -= b;
        ab.push_back(a+b);
    }

    sort(ab.begin(), ab.end(), greater<long long>());

    for(long long i = 0; i < n; i++){
        if(i % 2 == 0){
            ans += ab[i];
        }
    }

    cout << ans << endl;
    return 0;
}