#include <bits/stdc++.h>
#define FOR(i, l, r) for(ll i = l; i < r; i++)
#define rep(i, N) FOR(i, 0, N)
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<ll> vl;
const ll MOD = round(1e9+7);


int main() {
    int N; cin >> N;
    
    vector<bool> num(56565, true);
    num[1] = false; num[2] = true;
    for(int j = 2*2; j < 55565; j += 2){
        num[j] = false;
    }
    for(int i = 3; i*i < 55565; i+=2){
        if(num[i])
            for(int j = i*i; j < 55565; j += i*2){
                num[j] = false;
            }
    }

    queue<int> que;
    int tmp = 2;
    rep(i,N) {
        while(!num[tmp] || tmp%5 != 1) tmp++;
        que.push(tmp);
        tmp++;
    }

    while(!que.empty()){
        cout << que.front() << " ";
        que.pop();
    }
    return 0;
}
