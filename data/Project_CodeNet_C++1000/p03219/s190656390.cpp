#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
typedef long long ll;

const int INF = 1e9+7;

using ipair = pair<int, int>;

bool operator>(const ipair a,const ipair b){return a.first > b.first;}



int main(){
    int X, Y;
    cin >> X >> Y;

    cout << X + Y/2 << endl;

    return 0;
}