#include <bits/stdc++.h>
 
#define DEBUG(x)        do { std::cerr << #x << " = " << x << std::endl;  } while(0)
#define DEBUGV(x)       for(auto e : x) { std::cerr << e << " "; }; cout << endl;
#define INFO(msg)       do { std::cerr << msg << std::endl; } while(0)
#define ll              long long
#define vi              vector<int>
#define pii             pair<int, int>
#define fori(i, s, e)   for(int i = s; i < e; i++)
#define ford(i, s, e)   for(int i = s; i >= e; i--)
 
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x, s = 0;

    cin >> n >> x;
    vi v(n, 0);

    fori(i, 0, n) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for(auto el : v) {
        if(x >= el) {
            x-= el;
            s++;    
        }
    }

    int l;
    fori(i, 0, n) {
        l = x / v[i];
        s += l;
        x -= l * v[i];
    }

    cout << s << endl;

    return 0;
}
