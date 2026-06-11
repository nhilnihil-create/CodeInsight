#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll n, a, b;
    cin >> n >> a >> b;
    if(a * b < n || a + b > n + 1){
        cout << -1 << endl;
        return 0;
    }
    int h = 0;
    int l = 0;
    for(int i = 0; i < a - 1; i++){
        l = (n - b) / (a - 1) + 1;
        if(i >= (n - b) % (a - 1)) l--;
        h += l;
        for(int j = 0; j < l; j++) cout << h - j << " ";
    }
    for(int i = n; i > n - b; i--) cout << i << " ";
}