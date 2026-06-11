#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int d , n;

int main()
{
    _FastIO;    

    cin >> d >> n;
    if(n == 100)
        n++;
    cout << n;
    for(int i = 0; i < d; i++){
        cout << "00";
    }
    cout << endl;
    return 0;
}
