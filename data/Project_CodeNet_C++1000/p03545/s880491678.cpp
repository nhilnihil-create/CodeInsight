#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    string S;
    cin >> S;
    vector<int> val(4);
    for(int i=0; i<4; i++){
        val[i] = S[i] - '0';
    }

    int target = 7;
    int ans = val[0];

    for(int i=0; i < 1<<3; i++){
        ans = val[0];
        int x0 = (i >> 0) & 1;
        int x1 = (i >> 1) & 1;
        int x2 = (i >> 2) & 1;

        ans = (x0 == 0)? ans - val[1] : ans + val[1];
        ans = (x1 == 0)? ans - val[2] : ans + val[2];
        ans = (x2 == 0)? ans - val[3] : ans + val[3];

        if(ans == target){
            char c0 = (x0 == 0)? '-' : '+';
            char c1 = (x1 == 0)? '-' : '+';
            char c2 = (x2 == 0)? '-' : '+';
            cout << val[0] << c0 << val[1] << c1 << val[2] << c2 << val[3] << "=7" << endl;
            break;
        }
    }
    return 0;
}

