#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int n;
    cin >> n;
    
    vector<int> item(n);
    for(int i = 0; i < n; i++){
        cin >> item[i];
    }
    sort(item.rbegin(), item.rend());
    item[0] /= 2;
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += item[i];
    }
    cout << sum << endl;
    return 0;
}