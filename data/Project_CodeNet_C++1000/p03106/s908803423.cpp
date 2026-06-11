#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, k;
    cin >> a >> b >> k;
    vector<int>x;
    for(int i=1; i<=min(a, b); i++){
        if(a%i==0 && b%i==0) x.insert(x.begin(), i);
    }
    cout << x.at(k-1) << endl;
    return 0;
}

