#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int n , a , b;

int main()
{
    _FastIO;
    cin >> n;
    if(n == 1){
        cout << "Hello World" << endl;
        return 0;
    }
    cin >> a >> b;
    cout << a + b << endl;
    return 0;
}
