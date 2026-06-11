#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }

int main(){
    ll N;
    cin >> N;
    vector<string> s(N);
    rep(i,N){
        cin >> s[i];
    }
    ll cnt=0;
    ll a[3]={};
    rep(i,N){
        ll M = s[i].size();
        rep(j,M-1){
            if(s[i].substr(j,2) == "AB"){
                cnt++;
            }
        }
        if(s[i][0] == 'B' && s[i][M-1] == 'A'){
            a[0]++;
        }else if(s[i][0] == 'B'){
            a[1]++;
        }else if(s[i][M-1] == 'A'){
            a[2]++;
        }
    }
    bool flag = false;
    if(a[0] > 0){
        cnt += a[0]-1;
        flag = true;
    }
    if(flag){
        if(a[1]>0 && a[2]>0){
            cnt += min(a[1], a[2]) + 1;
        }else if(!(a[1] == 0 && a[2] == 0)){
            cnt += 1;
        }
    }else{
        cnt += min(a[1], a[2]);
    }
    cout << cnt << endl;
}
