#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    char x, y;
    cin >> x >> y;
    if(x < y) cout << '<' << endl;
    else if(x == y) cout << '=' << endl;
    else cout << '>' << endl;
    return 0;
}