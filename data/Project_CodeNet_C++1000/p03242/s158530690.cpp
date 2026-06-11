#include <bits/stdc++.h>
#define nl ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()
using namespace std;

int main() {
    nl // 	

    string s, temp;
    cin >> s;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == '1') temp.push_back('9');
        else temp.push_back('1');
    }
    cout << temp;
}	
