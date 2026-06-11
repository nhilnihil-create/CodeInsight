#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = (1LL<<59);

int main(){
    string s; cin >> s;
    int w; cin >> w;

    for(int i=0; i<s.size(); i++) if(i%w == 0) cout << s[i];
    cout << endl;
}