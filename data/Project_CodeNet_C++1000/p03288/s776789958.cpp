#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int k;

int main()
{
    _FastIO;
    cin >> k;
    if(k < 1200){
        cout << "ABC" << endl;
        return 0;
    }
    if(k < 2800){
        cout << "ARC" << endl;
        return 0;
    }
    cout << "AGC" << endl;
    return 0;
}
