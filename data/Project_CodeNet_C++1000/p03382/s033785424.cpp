#include<bits/stdc++.h>
#define pb push_back

typedef long long ll;
using namespace std;

typedef long double ldouble;

const ll MXN = 2e5 + 1;

int n, a[MXN], b[MXN], sum, ind;
double mn = MXN * 5000;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    for(int i = 1; i < n; i++){
        if(abs(b[i] - 1.0 * b[n] / 2) * 1.0 < mn){
            mn = abs(b[i] - 1.0 * b[n] / 2);
            ind = i;
        }
    }
    cout << b[n] << ' ' << b[ind];
    return 0;
}
