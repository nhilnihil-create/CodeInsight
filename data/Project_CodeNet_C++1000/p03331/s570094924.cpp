#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;

int findthedigt(int n){
    int sum = 0;
    while(n > 0){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main(){
    int N;
    cin >> N;
    vector<int> a(N-1);

    for(int i = 1;i < N;++i){
        a[i-1] = findthedigt(i) + findthedigt(N - i);
    }

    int mn  = a[0];
    for(int i = 0;i < N -1;++i){
        if(mn > a[i])mn = a[i];
    }
    
    cout << mn << endl;
} 