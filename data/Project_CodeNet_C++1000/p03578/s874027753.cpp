#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n,m;
    cin >> n;
    int d[n];
    for(int i = 0; i < n; i++){
        cin >> d[i];
    }
    cin >> m;
    int t[m];
    for(int i = 0 ; i < m; i++){
        cin >> t[i];
    }
    map<int,int> x,y;
    for(int i = 0; i < n; i++){
        x[d[i]]++;
    }
    for(int j = 0; j < m; j++){
        y[t[j]]++;
    }
    for(int i = 0; i < m; i++){
        int p = t[i];
        if(x[p] < y[p]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    return 0;
}