#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, w, n, sx, sy;
    string s,t;
    cin >> h >> w >> n 
        >> sx >> sy 
        >> s >> t;
    
    sx -= 1;
    sy -= 1;
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());

    int left = 0, right = w-1;// survival border
    for(int i=0; i<n; i++){
        if(i != 0){
            if(t[i] == 'L') right = min(right + 1, w-1);
            if(t[i] == 'R') left  = max(left  - 1, 0);
        }
        if(s[i] == 'L') left  += 1;
        if(s[i] == 'R') right -= 1;
        if(left > right){
            cout << "NO" << endl;
            return 0;
        }
    }
    int above = 0, below = h-1;// survival border
    for(int i=0; i<n; i++){
        if(i != 0){
            if(t[i] == 'U') below = min(below + 1, h-1);
            if(t[i] == 'D') above = max(above - 1, 0);
        }
        if(s[i] == 'U') above += 1;
        if(s[i] == 'D') below -= 1;
        if(above > below){
            cout << "NO" << endl;
            return 0;
        }
    }

    if(left  <= sy && sy <= right
    && above <= sx && sx <= below){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
    return 0;
}