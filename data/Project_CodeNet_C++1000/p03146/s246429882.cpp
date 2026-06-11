#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
using namespace std;
#define int long long
typedef vector<int> vi;

int f(int x){
    if(x % 2) return 3*x + 1;
    else return x / 2;
}

signed main(){
    int s;
    cin >> s;
    vi a(1000001);

    a[1] = s;
    for(int i = 2; i <= 1000001; i++){
        a[i] = f(a[i-1]);
    }

    for(int i = 1; i <= 1000001; i++){
        if(a[i] == 4 || a[i] == 2 || a[i] == 1){
            cout << i+3 << endl;
            return 0;
        }
    }

    return 0;
}