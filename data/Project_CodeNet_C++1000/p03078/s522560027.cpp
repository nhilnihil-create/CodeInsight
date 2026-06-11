#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    ll X, Y, Z, K;
    cin >> X >> Y >> Z >> K;
    vector<ll> A(X+1), B(Y+1), C(Z+1);
    for (int i = 0; i < X; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < Y; i++) {
        cin >> B[i];
    }
    for (int i = 0; i < Z; i++) {
        cin >> C[i];
    }
    A[X] = -100000000000;
    B[Y] = -100000000000;
    C[Z] = -100000000000;
    sort(ALL(A), greater<ll>());
    sort(ALL(B), greater<ll>());
    sort(ALL(C), greater<ll>());


    priority_queue<pair<ll,pair<int,iint>>> q;
    q.push(make_pair(A[0] + B[0] + C[0], make_pair(0, make_pair(0, 0))));

    pair<ll, pair<int, iint>> x;
    map<pair<int, iint>, bool> g;
    int a,b,c;
    for (int i = 0; i < K; i++) {
        x = q.top();
        q.pop();
        while(q.size() != 0 && q.top() == x){
            q.pop();
        }
        a = x.second.first;
        b = x.second.second.first;
        c = x.second.second.second;
        printf("%lld\n", x.first);
        
        if(a <= X-2 && !g.count(make_pair(a+1, make_pair(b, c)))){
            q.push(make_pair(A[a+1] + B[b] + C[c], make_pair(a+1, make_pair(b, c))));
            g[make_pair(a+1, make_pair(b, c))] = true;
        }
        if(b <= Y-2 && !g.count(make_pair(a, make_pair(b+1, c)))) {
            q.push(make_pair(A[a] + B[b+1] + C[c], make_pair(a, make_pair(b+1, c))));
            g[make_pair(a, make_pair(b+1, c))] = true;
        }
        if(c <= Z-2 && !g.count(make_pair(a, make_pair(b, c+1)))) {
            q.push(make_pair(A[a] + B[b] + C[c+1], make_pair(a, make_pair(b, c+1))));
            g[make_pair(a, make_pair(b, c+1))] = true;
        }
    }



}