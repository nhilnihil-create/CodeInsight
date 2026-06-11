#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define repn(i, n) for(int i = 1; i <= n; i++)
#define repr(i, n) for(int i = n-1; i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define lint long long

int main(){
    int n; cin >> n;

    long max_a = -1e7, min_a = 1e7;
    int max_i, min_i;
    rep(i, n){
        int x; cin >> x;
        if(x > max_a){
            max_a = x;
            max_i = i;
        }
        if(x < min_a){
            min_a = x;
            min_i = i;
        }
    }

    if(max_a > 0 && min_a < 0){
        cout << n * 2 - 1 << endl;
        if(max_a + min_a > 0){
            min_a = 1;
            rep(i, n){
                cout << max_i+1 << " " << (i+1) << endl;
            }
        }
        else{
            max_a = -1;
            rep(i, n){
                cout << min_i+1 << " " << (i+1) << endl;
            }
        }
    }
    else cout << n - 1 << endl;

    if(max_a >= 0 && min_a >= 0){
        rep(i, n-1){
            cout << (i+1) << " " << (i+2) << endl;
        }
    }
    else{
        rep(i, n-1){
            cout << (n-i) << " " << (n-i-1) << endl;
        }
    }
}