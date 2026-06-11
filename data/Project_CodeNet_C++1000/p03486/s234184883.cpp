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
    string s, t;
    cin >> s >> t;
    sort(all(s));
    sort(all(t), greater<char> ());

    if(s<t)
        cout << "Yes";
    else
        cout << "No";
}
