#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int h, w, h0, w0;
    cin >> h >> w >> h0 >> w0;
    cout << (h-h0)*(w-w0) << endl;
    return 0;
}