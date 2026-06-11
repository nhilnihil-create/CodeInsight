#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int m = (n/2)*2;
    int a = (m-2)*m/2;
    if(n%2 == 0) cout << a << endl;
    else cout << a+m << endl;
    for(int i=1; i<=m; i+=2){
        for(int j=i+2; j<=m; j+=2){
            cout << i << ' ' << j << endl;
        }
        for(int j=2; j<=m; j+=2){
            if(i+j==m+1) continue;
            cout << i << ' ' << j << endl;
        }
        for(int j=i+3; j<=m; j+=2){
            cout << i+1 << ' ' << j << endl;
        }
    }
    if(n%2 == 1){
        for(int i=1; i<n; i++){
            cout << i << ' ' << n << endl;
        }
    }
    return 0;
}
