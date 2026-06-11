#include<bits/stdc++.h>
#define pb           push_back
#define pii          pair<int,int>
#define vi           vector<int>
#define vpii         vector<pair<int,int>>
#define gph          map<int, vector<int>>
#define mp           make_pair
#define FOR(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD0(i, n) for (int i = (int)n; i >= 0; i--)
#define FORD1(i, n) for (int i = (int)n; i >= 1; i--)
#define FORS(i, n) for(; i < (int)(n); i++)
#define debug(X) { cout << #X << " = " << (X) << endl; }
#define printArr(A,n) { cout << #A << " = "; FOR(i,n) cout << A[i] << ' '; cout << endl; }
using namespace std;
int m[(1 << 26)];
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    memset(m,-1, sizeof m);
    string s;cin >> s;
//    unordered_map<int, int> m;

    m[0] = 0;
    int xr = 0;
    FOR(i, s.length()){
        xr  ^= (1 << (s[i] - 'a'));
        int ans= 1e9;
        for(int bi  = 0; bi < 26; bi++){
            if(m[xr ^ (1 << bi)] != -1){
                ans = min(ans, m[(xr ^ (1 << bi))] + 1);
            }
        }
        if(ans <= s.length()){
            if(xr != 0)m[xr]=ans;
        }
    }
    if(xr == 0)cout << 1;
    else cout << m[xr];
}


