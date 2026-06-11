#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
    // 制約見て！！！デカかったらlong longにすること！

    int N;
    cin >> N;
    int p[N];
    int maxim = -1;
    int sum = 0;
    rep(i,N){
        cin >> p[i];
        if(maxim < p[i]){
            maxim = p[i];
        }
        sum +=p[i];
    }
    sum -= maxim / 2;
    cout << sum<<endl;
}