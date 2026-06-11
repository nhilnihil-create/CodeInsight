#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

const int N = 2001;

int n;
bitset <N * N> b;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    b.set(0);
    int sum = 0;
    for(int i = 0 ; i < n ; i++){
        int x;
        cin >> x;
        sum += x;
        b |= b << x;
    }
    for(int i = (sum + 1) / 2 ; ; i++){
        if(b[i]) finish(i);
    }
}
