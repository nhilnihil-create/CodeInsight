#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int n;
    cin >> n;
    if(n == 1){
        cout << "Hello World" << endl;
    }
    else if(n == 2){
        int a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
    return 0;
}