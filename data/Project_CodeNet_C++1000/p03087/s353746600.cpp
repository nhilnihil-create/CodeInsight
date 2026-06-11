#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 100005

int n , q , l , r;
string s;
int p[MAXX];

int main()
{
    _FastIO;
    cin >> n >> q;
    cin >> s;
    for(int i = 1; i < n; i++){
        p[i + 1] = p[i];
        if(s[i - 1] == 'A' && s[i] == 'C')
            p[i + 1]++;
    }
    while(q--){
        cin >> l >> r;
        cout << (p[r] - p[l]) << endl;
    }
    return 0;
}
