#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h,w,r,c;
    cin >> h >> w >> r >> c;
    cout << (h-r)*(w-c) << "\n";

    return 0;
}