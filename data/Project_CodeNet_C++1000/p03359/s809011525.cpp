#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define INF 1999999999
#define MODA 1000000007
#define PI 3.1415926535897932384626433

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    if(a > b){
        cout << a-1 << endl;
    }
    else{
        cout << a << endl;
    }
    return 0;
}
