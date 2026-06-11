#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n, x;
    cin >> n >> x;

    vector<long long int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    long long int total = 0;
    for(int i=0; i<n; i++){
        total += a[i];
        if(total == x){
            cout << i+1 << endl;
            return 0;
        }
        else if(total > x){
            cout << i << endl;
            return 0;
        }
    }
    cout << n-1 << endl;
    return 0;
}