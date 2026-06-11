#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n; cin >> n;
    vector<int> X(n), Y(n);
    for (int i=0; i<n; i++){
        cin >> X[i];
        Y[i] = X[i];
    }
    sort(X.begin(), X.end());
    int m = n/2;
    for (int i=0; i<n; i++){
        if(Y[i]<X[m]) cout << X[m] << endl;
        else cout << X[m-1] << endl;
    }
}