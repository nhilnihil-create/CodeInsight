#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define GET_ARRAY_SIZE(a)   (sizeof(a)/sizeof(a[0]))
#define LL long long
LL facctorialMethod(LL k);
int main(){
    LL a,b,count,sum,ans;
    cin >> a >> b;
    count = b-a;
    sum = 0;
    for(int i = 1; i <= count; i++) {
        sum += i;
    }
    ans = sum - b;
    cout << ans << endl;
    return 0;
}

int facctorialMethod(int k){
    int sum = 1;
    for (int i = 1; i <= k; ++i){
        sum *= i;
    }
    return sum;
}