#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    int K;
    cin >> S >> K;

    map<string, bool> m;

    for(int i = 0; i < S.length(); i++) {
        string b = "";
        int c = 0;
        for(int j = i; j < S.length(); j++) {
            c++;
            b += S[j];
            m[b] = true;
            if(c == K) break;
        }
    }

    int c = 0;

    for(auto i = begin(m); i != end(m); i++) {
        c++;
        if(c == K) {
            cout << i -> first << endl;
            return 0;
        }
    }
}