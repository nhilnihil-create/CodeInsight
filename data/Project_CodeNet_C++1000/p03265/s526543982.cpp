#include <bits/stdc++.h>
using namespace std;
using pint = pair<int,int>;

const long long INFLL = 1LL << 60;
const int INFI = 1000000000;

int main(){
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    pint v;
    v.first = x2-x1; v.second = y2-y1;
    cout << x2-v.second << ' ' << y2+v.first << ' ';
    cout << x1-v.second << ' ' << y1+v.first << endl;
}
