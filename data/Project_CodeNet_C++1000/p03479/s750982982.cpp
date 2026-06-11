//
// Created by TakahiroYamaji on 2020/07/29.
//
#include<iostream>
#include<algorithm>
typedef long long ll;
ll X, Y;
int main(){
    std::cin >> X >> Y;
    ll res = 0;
    while (X <= Y){
        X = 2 * X;
        res++;
    }
    std::cout << res << std::endl;
}

