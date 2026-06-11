#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<map>
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x) << endl
typedef long long ll;
const ll MOD = 1000000007;
 
using namespace std;

queue<ll> que;

void pre(){
    ll x = 0;
    queue<ll> tmp;
    tmp.push(3);
    tmp.push(5);
    tmp.push(7);
    que = tmp;
    while(x < MOD){
        x = tmp.front();
        tmp.pop();
        for(int i=3; i<8; i+=2){
            tmp.push(x*10+i);
            que.push(x*10+i);
        }
    }
}

int main(){
    pre();
    int N, cnt, p;  cin >> N;
    ll x = 0;
    cnt = 0;
    while(x <= N){
        x = que.front();
        que.pop();
        p = 1;
        ll tmp = x;
        if(x <= N){
            while(tmp > 0){
                for(int i=3; i<8; i+=2) if(tmp%10 == i) p *= i;
                tmp /= 10;
            }
            if(p%105 == 0)  cnt++;
        }
    }
    print(cnt);
    return 0;
}