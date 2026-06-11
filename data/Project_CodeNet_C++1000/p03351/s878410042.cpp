#include <bits/stdc++.h>
#define rep(i,n) for(int (i) = 0; (i) < (n); ++(i))
#define _Pi 3.1415926535
using namespace std;
typedef long long ll;

int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(abs(a-c) <= d) cout << "Yes ";
    else if(abs(a-b) <= d && abs(b-c) <= d) cout << "Yes ";
    else cout << "No ";
    return 0;
}
