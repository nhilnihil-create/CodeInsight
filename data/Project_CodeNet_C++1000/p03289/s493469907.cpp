#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int k;

int main()
{
    _FastIO;
    string s;
    cin >> s;
    int n = s.size();
    int  sum = 0;
    for(int i = 0; i < n; i++){
        if(int(s[i]) < 97)
            sum++;
    }
    string ans = "AC";
    if(sum == 2 && s[0] == 'A'){
        ans = "AC";
    }
    else
        ans = "WA";
    sum = 0;
    for(int i = 2; i < n - 1; i++){
        if(s[i] == 'C')
            sum++;
    }
    if(sum && ans == "AC")
        cout << "AC" << endl;
    else
        cout << "WA" << endl;
    return 0;
}
