#include<bits/stdc++.h>

using namespace std;

#define Q int t; scanf("%d", &t); for(int q=1; q<=t; q++)
typedef long long int lli;
typedef pair<int, int> pi;
typedef pair<int, pi> node;


int main()
{
    lli gc = 0;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        lli a;
        cin >> a;
        gc = __gcd(a, gc);
    }
    cout << gc << "\n";

    return 0;
}
