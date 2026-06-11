#include <bits/stdc++.h>
using namespace std;
#define REP(i, init, n) for(int i = (int)(init); i < (int)(n); i++)

#define vi vector<int>
#define vl vector<long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long>>
#define pint pair<int, int>
#define plong pair<long, long>

int main() {
    string S;
    cin>>S;
    int ans = 0;
    REP(i, 0, S.size()){
        if(S[i] == '+') ans++;
        else ans--;
    }
    cout << ans << endl;
}