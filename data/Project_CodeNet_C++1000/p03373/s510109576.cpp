#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for(ll i = 0; i < n; i++)
ll MOD = 1e9 + 7;
int INF = 1 << 30;
ll INFL = 1LL << 60;

int main() {
    int A,B,C,X,Y;
    cin  >> A >> B >> C >> X >> Y;
    int D = 2*C;
    int Z = max(X,Y);
    int money = A*X+B*Y;
    rep(i,Z+1){
        if(i <= min(X,Y) ){
        int sum = A*(X-i)+B*(Y-i)+D*i;
        money = min(sum,money);
        }
        else if(i <= X && i > Y) {
        int sum = A*(X-i)+D*i;
        money = min(sum,money);
        }
        else {
        int sum = B*(Y-i)+D*i;
        money = min(sum,money);
        }
    }
    cout << money <<endl;
}