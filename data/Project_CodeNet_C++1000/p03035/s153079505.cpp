#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int a , b;

int main()
{
    _FastIO;
    cin >> a >> b;
    if(a < 6){
        cout << "0" << endl;
        return 0;
    }
    if(a < 13){
        cout << b / 2 << endl;
        return 0;
    }
    cout << b << endl;
    return 0;
}
