#include<bits/stdc++.h>
using namespace std;

int main() {
    int K;
    cin >> K;
    if(K%2==0){
        cout << (K/2)*(K/2); return 0;
    }
    cout << (K+1)/2*(K-1)/2;
return 0;
}
