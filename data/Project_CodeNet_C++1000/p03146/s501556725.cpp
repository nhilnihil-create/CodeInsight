#include <bits/stdc++.h>
using namespace std;

int main(){

    int s;
    cin >> s;

    map<int, int> pos;
    pos[s]++;

    int a_buf, a = s;
    int ans = 1;
    while(1){
        a_buf = a;
        if (a_buf%2 == 0) a = a_buf/2;
        else a = a_buf*3+1;
        pos[a]++;
        ans++;

        if (pos[a] == 2) break;
    }

    cout << ans << endl;
    return 0;
}