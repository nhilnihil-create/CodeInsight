#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int ans  = 0;
    if(a==b && b==c) ans = 0;
    else if(a==b && a!=c) ans = a-c;
    else if(a==c && a!=b) ans = a-b;
    else if(b==c && b!=a) ans = b-a;
    else {
        vector<int> d = {a, b, c};
        sort(d.begin(), d.end());
        ans = d.at(2) - d.at(1) + d.at(1) - d.at(0);
    }

    if(ans < 0) ans = ans * -1;

    cout << ans << endl;
}