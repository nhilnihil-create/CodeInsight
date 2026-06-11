#include<bits/stdc++.h>

using namespace std;

int main(){
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;

    vector<int> buys(4);
    buys.at(0) = A*X+B*Y;
    buys.at(1) = C*max(X,Y)*2;
    buys.at(2) = C*X*2+B*max(0,Y-X);
    buys.at(3) = C*Y*2+A*max(0,X-Y);

    int ans = *min_element(buys.begin(), buys.end());
    cout << ans << endl;
}