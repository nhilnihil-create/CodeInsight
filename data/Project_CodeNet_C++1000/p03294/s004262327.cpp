#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
typedef long long ll; 
using namespace std;
/*
time:
wa:
反省:
考察・解説:
*/
int main() {
    int n; cin >> n;
    vector<int>a(n);
    int sum = 0;
    int ans = 0;
    int mod_sum;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    cout << sum-n << endl;
    return 0;
}