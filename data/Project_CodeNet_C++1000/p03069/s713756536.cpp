#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000007
//0=48,A=65,a=97

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
 
    vector<int> lbfw(n);//left brack from white
    int nlb=0;//now left brack;

    for(int i = 0; i < n; i++) {
        if(s[i]=='#') nlb++;
        else lbfw[i]=nlb;
    } 

    int rw=0;//right white
    int ans=INF;

    for(int i = n-1; i >= 0; i--) {
        if(s[i]=='.'){
            ans = min(ans, lbfw[i]+rw);
            rw++;
        }
    }
    ans = min(ans, rw);
    if(ans==INF) ans = 0;

    cout << ans << endl;

    return 0;
}
