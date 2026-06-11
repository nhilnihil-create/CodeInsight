
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    string s;
    cin >> s;
    int blackstart=0;
    int whitestart=0;
    int n=s.size();
    for(int i=0; i<n; i++){
        //黒であるべきところが白だったら
        if(i%2==0 && s[i]=='1'){
            blackstart ++;
        }
        if(i%2==1 && s[i]=='0'){
            blackstart ++;
        }
    }
    for(int i=0; i<n; i++){
        if(i%2==1 && s[i]=='1'){
            whitestart ++;
        }
        if(i%2==0 && s[i]=='0'){
            whitestart ++;
        }
    }
    int ans = min(blackstart,whitestart);
    cout << ans << endl;


}