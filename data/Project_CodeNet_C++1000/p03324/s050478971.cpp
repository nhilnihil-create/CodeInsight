#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int func(int x) {
    if(x % 100 != 0)
        return 0;

    return func(x / 100) + 1;
}

int main() {
    // 制約見て！！！デカかったらlong longにすること！
    int d,n,cnt=0;
    cin >>d>>n;
    int i = 1;
    while(true){
        if(func(i)==d){
            cnt++;
        }
        if(cnt == n){
            cout << i <<endl;
            return 0;
        }
        i++;
    }
}