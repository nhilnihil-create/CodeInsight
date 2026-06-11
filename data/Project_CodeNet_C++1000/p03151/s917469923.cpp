#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000001
//0=48,A=65,a=97

int main() {
    int n;cin >> n;
    vector<int> a(n);for(int i=0;i<n;i++) cin >> a[i];
    vector<int> b(n);for(int i=0;i<n;i++) cin >> b[i];

    queue<int> q;
    priority_queue<int> p;
    int ans=0;

    for(int i = 0; i < n; i++) {
        int d=a[i]-b[i];
        if(d<0){
            ans++;
            q.push(d);
        }
        if(d>0){
            p.push(d);
        }
    }
    bool w=true;

    while(!q.empty() && !p.empty()){
        int x=p.top();p.pop();
        ans++;
        while(!q.empty()){
            int y=q.front();q.pop();
            if(x>=abs(y)){
                x += y;
            }
            else{
                y += x;
                q.push(y);
                break;
            }
        }
        if(q.empty()) {
            w=false;
            break;
        }
    }
    if(q.empty()) {
            w=false;
        }
    if(!w) cout << ans << endl;
    else cout << -1 << endl;

    return 0;
}