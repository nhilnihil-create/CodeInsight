#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    string N;
    cin >> N;
    if(N.size() > 1 && N[N.size()-1] != '9') {
        cout << N[0]-'0'+9*(N.size()-1)-1 << endl;
    }
    else {
        cout << N[0]-'0'+9*(N.size()-1) << endl;
    }
}
