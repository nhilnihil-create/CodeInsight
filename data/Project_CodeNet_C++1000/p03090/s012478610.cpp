#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    if(n%2){
        n--;
        cout << n*(n-1)/2 - n/2 + n << "\n";
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(i+j==n-1) continue;
                cout << i+1 << " " << j+1 << "\n";
            }
        }
        for(int i = 0; i < n; i++) {
            cout << n+1 << " " << i+1 << "\n";
        }
    }
    else{
        cout << n*(n-1)/2 - n/2 << "\n";
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(i+j==n-1) continue;
                cout << i+1 << " " << j+1 << "\n";
            }
        }
    }



    return 0;
}