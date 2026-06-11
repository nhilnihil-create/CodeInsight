#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
int main() {
    int n , b[101] , a[101] = {};
    bool f = true;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> b[i];
        if(b[i] > i + 1){
            f = false;
        }
    }
    if(f){
        for(int i = 0; i < n; i++){
            for(int j = 99; j >= b[i] - 1; j--){
                a[j + 1] = a[j];
            }
 
            a[b[i] - 1] = b[i];
        }
 
        for(int i = 0; a[i] != 0; i++){
            cout << a[i] << endl;;
        }
    }
    else{
        cout << -1;
    }
    return (0);
}
