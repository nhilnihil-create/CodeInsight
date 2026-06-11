#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int n , y;

int main()
{
    _FastIO;
    cin >> n >> y;
    if(y % 1000){
        cout << "-1 -1 -1" << endl;
        return 0;
    }
    y /= 1000;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            int x = y;
            x -= i * 10;
            x -= j * 5;
            if(x < 0)
                break;
            int s = i + j + x;
            if(s == n){
                cout << i << " " << j << " " << x << endl;
                return 0;
            }
        }
    }
    cout << "-1 -1 -1" << endl;
    return 0;
}
