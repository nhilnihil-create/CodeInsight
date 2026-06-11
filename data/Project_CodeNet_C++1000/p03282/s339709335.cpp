#include<bits/stdc++.h>
using namespace std;

int main() {
    string S;
    long long K;
    cin >> S >> K;
    for (long long i=0; i<K; i++) {
        if (S.at(i)!='1') {
            cout << S.at(i);
            return 0;
        }
    }
    cout << "1\n";
}