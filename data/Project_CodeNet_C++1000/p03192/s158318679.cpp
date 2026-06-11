#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int cnt = 0;
    string s;
    cin >> s;
    for(int i=0;i<4;i++){
        if(s[i]=='2') cnt++;
    }
    cout << cnt << endl;
    return 0;
}