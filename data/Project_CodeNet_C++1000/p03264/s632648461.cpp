#include <bits/stdc++.h>
using namespace std;

int K, odd, even;

int main(){
    cin >> K;
    even = K/2;
    odd = (K+1)/2;
    cout << even*odd << endl;
}