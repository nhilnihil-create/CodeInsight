#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    long long n, p;
    cin >> n >> p;
    long long ans = 1;
    vector<long long> v(1000001, 0);
    if(n == 1){
        cout << p << endl;
        return 0;
    }
    for (long long i = 2; i <= 1000000; ++i){
        while(p % i == 0){
            v[i]++;
            p = p / i;
            //cout << i << " ";
        }
    }
    //cout << endl;
    long long l = 0;
    for (long long i = 2; i <= 1000000; ++i){
        if(v[i] >= n){
            l = v[i] / n;
            for (long long j = 0; j < l; ++j){
                ans *= i;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
