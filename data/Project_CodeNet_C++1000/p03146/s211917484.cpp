#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    int s;
    cin >> s;
    vector<int> a(1000005, 0);
    a[s] = 1;
    int m = 1;
    while(1){
        m++;
        if(s % 2 == 1){
            s = 3 * s + 1;
        }
        else{
            s = s / 2;
        }
        a[s]++;
        if(a[s] == 2){
            printf("%d\n", m);
            break;
        }

    }
    

    
}