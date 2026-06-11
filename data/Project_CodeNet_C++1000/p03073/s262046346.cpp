#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string s;
    cin >> s;

    int count1=0, count2=0;
    rep(i, s.size()) {
        if ((i%2)!=(s.at(i)-'0')) count1++;
        if (((i+1)%2)!=(s.at(i)-'0')) count2++; 
    }

    if (count1<count2) cout << count1 << endl;
    else    cout << count2 << endl;
    return 0;
}