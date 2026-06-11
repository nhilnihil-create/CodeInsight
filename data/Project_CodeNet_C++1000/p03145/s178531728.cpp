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
    int a,b,c; cin >> a >> b >> c;
    if(a > b && a > c){
        printf("%d\n", b*c/2);
    }
    else if(b > a && b > c){
        printf("%d\n", a*c/2);
    }
    else{
        printf("%d\n", a*b/2);
    }


}