
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()


int main(){
    int n;
    string s;
    cin >> n >> s;

    int ans=0;
    rep(i,n){
        int cnt=0;
        //forループはchar型でもできる
        for(char c='a'; c<='z'; c++){
            bool left=false, right=false;
            rep(j,i){
                if(s[j] == c)left=true;
            }
            for(int j=i;j<n;j++){
                if(s[j]==c)right =true;
            }
            if(left && right) cnt++;
        }
        if(ans<cnt) ans=cnt;
    }
    cout << ans << endl;
}