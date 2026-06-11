#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int n , x;

int main()
{
    _FastIO;
    cin >> n;
    set<int> s;
    for(int i = 0; i < n; i++){
        cin >> x;
        s.insert(x);
    }
    cout << s.size() << endl;
    return 0;
}
