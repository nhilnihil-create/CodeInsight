#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
#define pii pair<int, int>
#define all(a) a.begin(),a.end()

template <typename T>
inline T gcd(T a, T b) { while (b != 0) swap(b, a %= b); return a; }

int main(){
    int d, n;
    cin >> d >> n;
    if(n==100)
        cout << 101 << string((d>0)?2*d:0,'0');
    else
        cout << n << string((d>0)?2*d:0,'0');
}
