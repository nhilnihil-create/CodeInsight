#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int n , m , s;
int l[MAXX];

int main()
{
    _FastIO;
    cout.precision(10);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> l[i];
        s += l[i];
        m = max(m , l[i]);
    }
    string ans = "Yes";
    s -= m;
    if(m >= s){
        ans = "No";
    }
    cout << ans << endl;
    return 0;
}
