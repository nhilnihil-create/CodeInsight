#include<bits/stdc++.h>
using namespace std;
using ull = long long;
int main(){
    ull n, a, b, c, d, e;
    cin >> n >> a >> b >> c >> d >> e;

    ull shortest = min(a, b);
    shortest = min(shortest, c);
    shortest = min(shortest, d);
    shortest = min(shortest, e);
    /*ull warizan=0;
    warizan = ceil(n / shortest);

    ull ans =0;
    ans = warizan + 5 - 1;*/
    cout << max({(n-1)/a, (n-1)/b, (n-1)/c, (n-1)/d, (n-1)/e}) + 5 << endl;
    return 0;
}