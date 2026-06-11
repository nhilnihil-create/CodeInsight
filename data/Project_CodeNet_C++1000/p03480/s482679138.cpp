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
    string s;
    cin>>s;
    int s_size = s.size();
    int count = 1;
    int ans = s_size;
    REP(i, 1, s_size){
        if(s[i-1] != s[i]){
            ans = min(ans, max(i, s_size-i));
        }
    }
    cout << ans << endl;
}