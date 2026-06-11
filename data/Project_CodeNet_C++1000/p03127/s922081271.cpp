#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const int MAX = 100000;
static const int NIL = -1;
using namespace std;


int main() {

    int n; cin >> n;
    vector<ll> v(n);
    priority_queue< ll, vector<ll>, greater<ll> > q;
    rep(i,n){
        cin >> v[i];
        q.push(v[i]);
    }

    while (q.size() > 1) {
        ll first = q.top();
        q.pop();
        ll second = q.top();
        q.pop();
        q.push(first);
        if(second%first != 0) q.push(second%first);

    }
    cout << q.top();



    return 0;
}
