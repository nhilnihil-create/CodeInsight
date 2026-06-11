#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll zero = 0;
const ll INF = 10000000000000000; //10^16
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    int N , K;
    cin >> N >> K;
    K = min(N,K);
    string S;
    cin >> S;
    vector<int> a(4*N+2, 0);
    a[0] = 0; a[1] = 0;
    int cnt = 0;
    int nowi = 2;
    char tmpchar = '0';
    for(char i: S){
        if(i == tmpchar){
        }
        else{
            a[nowi] = cnt;
            nowi++;
            tmpchar = i;
        }
        cnt++;
    }
    for(;nowi < 4*N+2; nowi++){
        a[nowi] = cnt;
    }
    int maxi = 0;
    for (int i = 0; i < 4*N-(2*K+1); i += 2) {
        maxi = max(maxi, a[i+2*K+1]-a[i]);
    }
    printf("%d\n", maxi);
}
