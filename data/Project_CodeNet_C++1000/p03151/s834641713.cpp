#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
int main(){
    int n;
    cin >> n;
    int a[n],b[n];
    rep(i,n)cin >> a[i];
    rep(i,n)cin >> b[i];
    vector<ll>sa(n);
    rep(i,n)sa[i] = a[i] - b[i];
    sort(all(sa));
    ll les = 0;
    int lcnt = 0;
    rep(i,n){
        if(sa[i] < 0){
            les += abs(sa[i]); 
            lcnt++;
        }
    }
    reverse(all(sa));
    ll yo = 0;
    int cnt = 0;
    while(yo < les){
        if(cnt >= n){
            cout << -1 << endl;
            return 0;
        }
        if(sa[cnt] < 0){
            cout << -1 << endl;
            return 0;
        }
        yo += sa[cnt];
        cnt++;
    }
    cout << lcnt + cnt << endl;
    //cout << les << ' ' << yo << endl;
    return 0;
}