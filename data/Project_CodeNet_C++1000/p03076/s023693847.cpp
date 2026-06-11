#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int>usi(5);
    for(int i = 0; i < 5; i++) {
        cin >> usi[i];
    }
    int ans = 1000;
    do{
        int cnt = 0;
        cnt+=(usi[0]+9)/10*10;
        cnt+=(usi[1]+9)/10*10;
        cnt+=(usi[2]+9)/10*10;
        cnt+=(usi[3]+9)/10*10;
        cnt+=usi[4];
        ans = min(ans,cnt);
    }while(next_permutation(usi.begin(), usi.end()));
    cout << ans << endl;
}