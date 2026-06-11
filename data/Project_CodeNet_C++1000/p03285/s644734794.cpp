#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x ,n) for(int i = x; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main(){
    int n,price=0;
    cin >> n;
    rep(cake,26){
        rep(donut,15){
            if(cake*4+donut*7==n){
                cout << "Yes";
                return 0;
            }
        }
    }
    
    cout << "No";
    
    return 0;
}