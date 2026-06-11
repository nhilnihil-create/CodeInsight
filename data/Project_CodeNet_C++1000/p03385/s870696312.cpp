#include <bits/stdc++.h>
#define rep0(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<string, int, int> TU;
typedef tuple<int, int, int> TI;

int main()
{
    string s;
    cin >> s;
    int dp[3] = {};
    rep0(i,3){
        if(s[i]=='a'){
            dp[0]++;
        }else if (s[i]=='b')
        {
            dp[1]++;            
        }else{
            dp[2]++;
        }
        
    }
    rep0(i,3){
        if(dp[i]!=1){
            cout << "No" << endl;
            return 0 ;
        }
    }
    cout << "Yes" << endl;
}
