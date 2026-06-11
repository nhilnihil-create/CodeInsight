#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
using namespace std;
#define INF 1e18LL

const ll MAX = 1000000000000000000; //1e18

int main(){
    int a, b, k;
    cin >> a >> b >> k;
    if(((b-a+1)/2)+1 <= k){
        for(int i = a; i <= b; i++){
            cout << i << endl;
        }
        return 0;
    }else{
        for(int i = a; i < a+k; i++){
            cout << i << endl;
        }
        for(int i = b-k+1; i <= b ; i++){
            cout << i << endl;
        }
    }
}

