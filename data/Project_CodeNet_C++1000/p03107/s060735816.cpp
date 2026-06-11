#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main(){
    Hello
    int one = 0, zero = 0;
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '1') one++;
        else zero++;
    }
    cout << min(one, zero) * 2;
    return 0;
}
