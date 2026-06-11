#include<bits/stdc++.h>
using namespace std;

using i64 = long long int;

i64 digit_sum(i64 n){
    i64 res = 0;
    while(n > 0){
        res += n % 10;
        n /= 10;
    }
    return res;
}

i64 power(i64 a, i64 b){
    i64 res = 1;
    for(i64 i=0;i<b;++i)res *= a;
    return res;
}

int main(){
    i64 k;
    cin >> k;

    vector<i64> v;
    for(i64 i=1;i<1000000;++i){
        i64 tmp = i;
        for(i64 j=0;j<=10;++j){
            v.push_back(tmp);
            tmp *= 10;
            tmp += 9;
        }
    }

    sort(v.rbegin(), v.rend());
    auto result = unique(v.begin(), v.end());
    v.erase(result, v.end());

    vector<i64> space;
    long double mini = 1e15;
    for(auto e : v){
        long double tmp = (long double)e / (long double)digit_sum(e);
        if(tmp <= mini){
            space.push_back(e);
            mini = tmp;
        }
    }

    sort(space.begin(), space.end());

    for(i64 i=0;i<k;++i){
        cout << space[i] << endl;
    }

    return 0;
}
