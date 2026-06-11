#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    cout << (long long)(m * 1900 + (n - m) * 100) * (long long)pow(2,m) << endl;
}
