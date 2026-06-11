#include <iostream>
#include <queue>
#define ll long long
#define MAXN 1000005
using namespace std;
struct node {
    ll num, step;
    node(){}
    node(ll n, ll s) : num(n), step(s){}
};
deque <node> q;
bool vst[MAXN];
ll k;
void slove() {
    q.push_front(node(1, 1));
    while(!q.empty()) {
        node t = q.front();
        q.pop_front();
        if(vst[t.num]) continue;
        vst[t.num] = 1;
        if(t.num == 0) {
            cout << t.step << "\n";
            return;
        }
        q.push_front(node(t.num*10%k, t.step));
        q.push_back(node((t.num+1)%k, t.step+1));
    }
}

int main () {
    cin >> k;
    slove();
    return 0;
}