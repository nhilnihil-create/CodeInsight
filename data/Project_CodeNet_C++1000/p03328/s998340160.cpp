#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int a,b;
    cin >> a >> b;
    int dif = b-a;
    int h = 0;
    rep(i,dif){
        h+=i;
    }
    cout << h - a << endl;
    return 0;
}