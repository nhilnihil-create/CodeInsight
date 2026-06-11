#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
    // 制約見て！！！デカかったらlong longにすること！
    int N;
    cin >> N;
    int a;
    int max = -1,min = -1;
    rep(i,N){
        cin >> a;
        if (max == -1 || a > max)
            max = a;
        if (min == -1 || a < min)
            min = a;
    }

    cout<< max - min <<endl;
}