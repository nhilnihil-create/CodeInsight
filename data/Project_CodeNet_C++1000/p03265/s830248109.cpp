#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2; 
    P u = make_pair(x2-x1, y2-y1);
    int x4 = x1 - u.second;
    int y4 = y1 + u.first;
    int x3 = x2 - u.second;
    int y3 = y2 + u.first;
    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
}