#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000001
//0=48,A=65,a=97

int main() {
    int n,m;cin >> n >> m;
    vector<int> a(n);for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    vector<P> d(m);
    for(int i = 0; i < m; i++) {
        int b,c;cin >> b >> c;
        d[i]=P(c,b);
    }
    sort(d.begin(),d.end());
    reverse(d.begin(),d.end());
    queue<P> q;
    for(int i = 0; i < m; i++) {
        q.push(d[i]);
    }

    int b=0,c=0;
    for(int i = 0; i < n; i++) {

        if(b==0 && q.empty()) break;
        if(b==0){
            P p=q.front();q.pop();
            c=p.first;
            b=p.second;
        }

        if(a[i]<c){
            a[i]=c;
            b--;
        }
        else break;

    }

    ll sum=0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
    }

    cout << sum << endl;

    return 0;
}