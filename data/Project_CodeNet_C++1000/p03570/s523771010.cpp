#include<bits/stdc++.h>

using namespace std;

const int INF=1e9;
int dp[1<<26];

int main(){
        string s;
        int n, bit=0;
        cin>>s;
        n=s.size();
        for(int i=0;i<(1<<26);i++){
                dp[i]=INF;
        }
        dp[0]=0;
        for(int i=0;i<n;i++){
                bit^=1<<(s[i]-'a');
                for(int j=0;j<26;j++){
                        dp[bit]=min(dp[bit], dp[bit^(1<<j)]+1);
                }
        }
        //答えが0になる時は答えを1にするようにする。
        cout<<max(1, dp[bit])<<endl;
        return 0;
}
