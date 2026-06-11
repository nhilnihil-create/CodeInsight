#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int a , b , c , d , e , k;

int main()
{
    _FastIO;
    cin >> a >> b >> c >> d >> e >> k;
    int x = max(max(max(a , b) , max(c , d)) , e);
    int y = min(min(min(a , b) , min(c , d)) , e);
    if((x - y) <= k){
        cout << "Yay!" << endl;
    }
    else
        cout << ":(" << endl;
    return 0;
}
