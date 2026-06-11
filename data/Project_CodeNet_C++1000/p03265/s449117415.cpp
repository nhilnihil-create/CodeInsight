#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << x2+y1-y2 << " " << y2+x2-x1 << " " << x1+y1-y2 << " " << y1+x2-x1 << endl;    
}
