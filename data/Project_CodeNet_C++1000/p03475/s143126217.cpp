#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll zero = 0;
const ll INF = 10000000000000000; //10^16
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

struct CSF{
    int C;
    int S;
    int F;
};

int main(){
    int N;
    cin >> N;
    vector<CSF> x(N-1);
    for (int i = 0; i < N-1; i++) {
        cin >> x[i].C >> x[i].S >> x[i].F;
    }
    int t;
    for (int i = 0; i < N; i++) {
        t = 0;
        for (int j = i; j < N-1; j++) {
            if(t <= x[j].S){
                t = x[j].S + x[j].C;
            }
            else{
                t = (1 + (t-1)/x[j].F) * x[j].F + x[j].C;
            }
        }
        printf("%d\n", t);
    }

}
