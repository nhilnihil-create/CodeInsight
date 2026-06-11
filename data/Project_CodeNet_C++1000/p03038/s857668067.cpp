#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main()
{
    // input
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    priority_queue<P> q;
    int b,c;
    rep(i,m){
        cin >> b >> c;
        q.push(make_pair(c,b));
    }

    // solve
    sort(ALL(a));
    ll ans = 0;
    b = q.top().second;
    c = q.top().first;
    q.pop();
    rep(i,n){
        if(c >= a[i]){
            ans += c;
            b--;
            if(b == 0){
                if(q.empty()){
                    c = 0;
                    b = 100005;
                }else{
                    b = q.top().second;
                    c = q.top().first;
                    q.pop();
                }
            }
        }else{
            ans += a[i];
        }
    }


    // output
    cout << ans << endl;
    return 0;
}