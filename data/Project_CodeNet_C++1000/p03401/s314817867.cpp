#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    int a[n+2];
    a[0] = 0;
    a[n+1] = 0;
    for(int i = 1; i < n+1; i++){
        cin >> a[i];
    }
    int sum = 0;
    for(int i = 0; i < n+1; i++){
        sum += abs(a[i] - a[i+1]);
    }
    for(int i = 1; i < n+1; i++){
        int p = abs(a[i-1] - a[i+1]);
        int q = abs(a[i-1] - a[i]) + abs(a[i] - a[i+1]);
        cout << sum + p - q << endl; 
    }

    return 0;
}