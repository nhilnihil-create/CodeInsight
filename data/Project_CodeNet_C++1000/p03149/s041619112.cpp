#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD = 1000000007, INF = 1e9;

int main()
{
    set<int> s;
    rep(i, 4){
        int a;
        cin >> a;
        s.insert(a);
    }
    if(s.count(1) && s.count(4) && s.count(7) && s.count(9)){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
}