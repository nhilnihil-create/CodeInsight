#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    string s;
    cin >> s;
    if(s.size()==3){
        reverse(s.begin(),s.end());
    }
    cout << s << endl;
}