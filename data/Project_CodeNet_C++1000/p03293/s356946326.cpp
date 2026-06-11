#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int ,int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005


int main()
{
    _FastIO;
    string s;
    string t;
    cin >> s;
    cin >> t;
    int n = t.size();
    while(n){
        if(t == s){
            cout << "Yes" << endl;
            return 0;
        }
        t += t[0];
        t.erase(t.begin());
        n--;
    }
    if(t == s){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}
