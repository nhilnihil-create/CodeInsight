#include<bits/stdc++.h>
using ll = long long;
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<ll> L(n+1);
    L[0] = 2; L[1] = 1;
    for(int i=2; i<=n; i++) L[i]=0;
    for(int i=2; i<=n; i++){
        L[i] = L[i-1] + L[i-2];
    }
    cout << L[n] << endl;
    return 0;
}