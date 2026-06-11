#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000007
//0=48,A=65,a=97

int main() {
    string s;cin >> s;
    int z=0,one=0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i]=='0') z++;
        else one++;
    }

    cout << 2*min(z,one) << endl;

    return 0;
}