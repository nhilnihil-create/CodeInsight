#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

const int e = 2e6 + 69;
const ll mod = 1e9 + 7;

ll a[e];

int main()
{
    string s;
    cin >> s;
    int cur = (s[0]-'0')*10 + s[1]-'0';
    int cur1 = (s[2]-'0')*10 + s[3]-'0';
    bool chk1 = false, chk2 = false;
    if(cur >= 1 && cur <= 12) chk1 = true;
    if(cur1 >= 1 && cur1 <= 12) chk2 = true;
    if(chk1 && chk2){
        cout << "AMBIGUOUS";
        return 0;
    }
    if(chk2){
        cout << "YYMM";
        return 0;
    }
    if(chk1){
        cout << "MMYY";
    return 0;
    }
    cout << "NA";
}
