#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;

 
int main(){
        int n,channel;
        cin >> n >> channel;
        vector<vector<int>> time(30,vector<int>(100005,0));
        rep(i,n){
                int s,t,c;
                cin >> s >> t >> c;
                --c;
                for(int i=s;i<=t;i++) time[c][i] = 1;
        }

        rep(j,100004){
                rep(i,channel-1) time[i+1][j] += time[i][j];
        }

        int ans = 0;
        rep(j,100005) ans = max(ans,time[channel-1][j]);
        cout << ans << endl;

        return 0;
}




