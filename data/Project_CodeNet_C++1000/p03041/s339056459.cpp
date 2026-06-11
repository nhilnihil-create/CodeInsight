#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main(){
    Hello
    int n, k;
    string s;
    cin >> n >> k >> s;
    if(s[k - 1] == 'A') s[k - 1] = 'a';
    if(s[k - 1] == 'B') s[k - 1] = 'b';
    if(s[k - 1] == 'C') s[k - 1] = 'c';
    cout << s;
    return 0;
}
