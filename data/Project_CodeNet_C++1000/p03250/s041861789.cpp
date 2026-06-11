#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> a(3);
    for (int i = 0;i < 3; i++){
        cin >> a[i];
    }
    sort(begin(a), end(a), greater<>());
    cout << (10*a[0])+a[1]+a[2] << endl;
    return 0;
}