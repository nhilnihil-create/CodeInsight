#include <iostream>
#include <queue>
#define ll long long
#define up (ll)1e10
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
        vst[t.num] = 1;
        if(t.num == 0) {
            cout << t.step << "\n";
            return;
        }
        q.pop_front();
        if(!vst[t.num*10%k]) 
            q.push_front(node(t.num*10%k, t.step));
        if(!vst[(t.num+1)%k]) 
            q.push_back(node((t.num+1)%k, t.step+1));
    }
}

int main () {
    cin >> k;
    slove();
    return 0;
}