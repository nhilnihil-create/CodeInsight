#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<int>>;
const int INT_INF = 1001001001;

int main(){
    int n,m;
    cin >> n >> m;
    int sum = m*1900 + 100*(n-m);
    cout << sum * pow(2,m) << endl;
}