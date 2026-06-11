#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
using namespace std;
typedef vector<int> vi;

int main(){
    string S;
    cin >> S;
    int ans = 9999;
    
    rep(i, S.size()-2){
        string tmp;
        tmp = tmp + S[i] +S[i+1] + S[i+2];
        int tmpnum = stoi(tmp);
        ans = min(ans, abs(753 - tmpnum));
    }

    cout << ans << endl;
    return 0;
}