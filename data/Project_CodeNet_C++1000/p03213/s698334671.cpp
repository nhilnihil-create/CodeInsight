#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;

    vector<int> factor(n+1);
    for(int i = 2; i <= n; i++){
        int cur = i;
        for(int j = 2; j <= i; j++){
            while(cur % j == 0){
                factor[j]++;
                cur /= j;
            }
        }
    }

    auto num = [&](int m){
        int res = 0;
        for(auto p : factor){
            if(p >= m-1) res++;
        }
        return res;
    };

    cout << num(75) + num(25) * (num(3)-1) + num(15) * (num(5) - 1)
        + num(5) * (num(5)-1) / 2 * (num(3)-2) << endl;

    return 0;
}