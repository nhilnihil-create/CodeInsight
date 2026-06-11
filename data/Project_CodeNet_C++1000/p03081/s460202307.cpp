#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    string s;
    cin >> n >> q >> s;

    vector<char> t(q), d(q);
    for(int i=0; i<q; i++){
        cin >> t[i] >> d[i];
    }

    int upper = n+1, lower = 0, mid;
    while(upper - lower > 1){
        mid = (upper + lower) / 2;

        int current = mid;
        for(int i=0; i<q; i++){
            if(s[current-1] == t[i]){
                if(d[i] == 'L') current -= 1;
                if(d[i] == 'R') current += 1;
            }
            if(current == 0 || current == n+1) break;
        }
        if(current == 0) lower = mid;
        else upper = mid;
    }
    
    int ans = lower;
    upper = n+1, lower = 0;
    while(upper - lower > 1){
        mid = (upper + lower) / 2;

        int current = mid;
        for(int i=0; i<q; i++){
            if(s[current-1] == t[i]){
                if(d[i] == 'L') current -= 1;
                if(d[i] == 'R') current += 1;
            }
            if(current == 0 || current == n+1) break;
        }
        if(current == n+1) upper = mid;
        else lower = mid;
    }

    ans = (upper - 1) - ans;
    cout << ans << endl;
    return 0;
}