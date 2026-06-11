#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>v(n + 3);
    int mx = -1e7, mn = 1e7, a = -1, b = -1;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        if(v[i] > mx){
            a = i;
            mx = v[i];
        }
        if(v[i] < mn){
            b = i;
            mn = v[i];
        }
    }
    if(abs(mx) >= abs(mn)){
        cout << 2 * n - 1 << '\n';
        for(int i = 1; i <= n; i++){
            if(i != a){
                v[i] = v[i] + mx;
                cout << a << ' ' << i << '\n';
            }
        }
        v[a] = v[a] + mx;
        cout << a << ' ' << a << '\n';
        for(int i = 2; i <= n; i++){
            v[i] = v[i - 1] + v[i];
            cout << i - 1 << ' ' << i << '\n';
        }
    }
    else{
        cout << 2 * n - 1 << '\n';
        for(int i = 1; i <= n; i++){
            if(i != b){
                v[i] = v[i] + mn;
                cout << b << ' ' << i << '\n';
            }
        }
        v[b] = v[b] + mn;
        cout << b << ' ' << b << '\n';
        for(int i = n - 1; i >= 1; i--){
            v[i] = v[i + 1] + v[i];
            cout << i + 1 << ' ' << i << '\n';
        }
    }
    return 0;
}