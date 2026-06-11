#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
int main() {
    string s;
    cin >> s;
    ll  count = 0 , sum = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'W'){
            sum += (i - count);
            count++;
        }
    }
    cout << sum << endl;
}
