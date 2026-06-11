#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;

int main(){
    ll a, b, c, k;
    cin >> a >> b >> c >> k;
    cout << (k%2 == 0 ? a-b : b-a)  << endl;

    return 0;
}