#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
int main(){
    int n;
    cin >>  n;
    int acnt = 0;
    int bcnt = 0;
    int cnt = 0;
    int abcnt = 0;
    string s;
    rep(i,n){
        cin >> s;
        int m = s.size();
        rep(j,m-1){
            if(s[j]=='A' && s[j+1] == 'B'){
                cnt++;
                //cout << i << ' ' << j << endl;
            }
        }
        if(s[0]=='B' && s[m-1]=='A')abcnt++;
        else if(s[0]=='B')bcnt++;
        else if(s[m-1]=='A')acnt++;
        
    }
    int sum = 0;
    if(acnt == 0 && bcnt == 0)abcnt= max(0,abcnt-1);
    cout << cnt + min(acnt+abcnt,bcnt+abcnt) << endl;
    return 0;
}