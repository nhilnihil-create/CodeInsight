#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int s;
    cin >> s;
    int x, y;
    x = s / 100;
    y = s % 100;
    string ans1, ans2;
    if (x == 0 || x > 12){
        ans1 = "YY";
    }
    else {
        ans1 = "MM";
    }
    if (y == 0 || y > 12){
        ans2 = "YY";
    }
    else {
        ans2 = "MM";
    }

    string ans;
    if (ans1 + ans2 == "YYYY"){
        ans = "NA";
    }
    else if (ans1 + ans2 == "MMMM"){
        ans = "AMBIGUOUS";
    }
    else{
        ans = ans1 + ans2;
    }
    cout << ans << endl;
    return 0;
}