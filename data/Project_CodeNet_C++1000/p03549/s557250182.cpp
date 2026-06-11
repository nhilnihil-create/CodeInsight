#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using P = pair<int, int>;

#define roop(i, n) for(int i = 0;i < n;i++)

int func(int m){
    int temp = 1;
    for(int i = 0;i < m;i++){
        temp *= 2;
    }

    return temp;
}

int main(void){

    int n, m;
    cin >> n >> m;

    cout << (1900*m+100*(n-m))*func(m);

    return 0;
}