#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
/*
time:
wa:
反省:
考察:
*/
int main() {
    int n; cin >> n;
    vector<long long> L(n+1);
    L[0] = 2;
    L[1] = 1; 
    for(int i = 2; i < n+1; i++){
        L[i] = L[i-1] + L[i-2];
    }
    cout << L[n] << endl;
    return 0;
}