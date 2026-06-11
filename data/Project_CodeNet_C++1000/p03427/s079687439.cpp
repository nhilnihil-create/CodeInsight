#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'

int main(){
    string n;
    cin >> n;
    int k = n.length();
    int ans = 9*(k-1)+int(n[0]-'0');
    if(n.substr(1) == string(n.length()-1, '9'))
        cout << ans;
    else
        cout << ans-1;
}
