#include <iostream>
#include <string>
using namespace std;

const int INF = 1000000000;

int d[70000000];

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i < (1 << 26); i++) d[i] = INF;
    int b = 0;
    d[0] = 0;
    for(int i = 0; i < n; i++){
        b ^= (1 << (s[i] - 'a'));
        for(int j = 0; j < 26; j++) d[b] = min(d[b], d[b ^ (1 << j)] + 1);
    }
    if(b == 0) cout << 1 << endl;
    else cout << d[b] << endl;
}