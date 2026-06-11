#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    vector<string> a(3); 
    rep(i, 3) {
        cin >> a[i];
    }

    cout << a[0][0] << a[1][1] << a[2][2] << endl; 

    return 0;
}