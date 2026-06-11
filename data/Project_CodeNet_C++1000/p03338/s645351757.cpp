#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int n;
    string s;
    cin>>n>>s;
    int ans=0,cnt;
    for (int i=1; i<n; i++) {
        cnt=0;
        for (char c='a'; c<='z'; c++) {
            bool left=false,right=false;

            for (int j=0; j<i; j++) {
                if (s[j]==c) left=true;
            }
            for (int j=i; j<n; j++) {
                if (s[j]==c) right=true;
            }
            if (left&&right) cnt++;
        }
        if (ans<cnt) ans=cnt;
    }
    cout<<ans<<endl;
}
