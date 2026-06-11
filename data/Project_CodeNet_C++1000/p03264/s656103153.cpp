#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main() {
    int K;
    cin >> K;
    if(K%2==0){
        cout << pow(K/2,2) << endl;
    }
    else{
        cout << K/2 * (K/2 +1) << endl;
    }
}
