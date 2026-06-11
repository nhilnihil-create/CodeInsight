#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;

int main(){
    int n,m;
    cin >> n >> m;
    cout << (1900*m+100*(n-m))*(1<<m) << endl;
}