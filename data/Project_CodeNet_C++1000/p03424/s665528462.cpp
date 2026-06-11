#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    bool f =0;
    char c;
    for (int i = 0; i < N; i++) {
        cin >> c;
        if (c =='Y') f = 1;
    }
    if(f == 0) cout << "Three" << endl;
    else cout << "Four" << endl;
}