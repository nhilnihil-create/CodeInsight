#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n,y;
    cin >> n >> y;

    for (int i = 0; i < n+1; i++){
        for (int j = 0; j < n+1-i; j++){
            if(10000*i+5000*j+1000*(n-i-j)==y){
                cout << i << " " << j << " " << n-i-j << endl;
                exit(0);
            }
        }
    }
    cout << "-1 -1 -1" << endl;
}

