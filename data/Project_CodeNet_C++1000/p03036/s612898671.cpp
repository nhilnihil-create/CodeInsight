#include <bits/stdc++.h>
using namespace std;
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
#define ft first
#define sd second
#define pb push_back
#define pob pop_back()
#define pf push_front
#define pof pop_front()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<char,char> pcc;
typedef pair<long long,long long> pll;

int main() {
    fastIO;
    ll r, d, x;
    cin >> r >> d >> x;
    for(int i = 0; i < 10; i++){
        x = r * x - d;
        cout << x << endl;
    }
    return 0;
}

