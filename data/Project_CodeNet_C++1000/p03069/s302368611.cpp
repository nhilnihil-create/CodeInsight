#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll zero = 0;
const ll INF = 10000000000000000; //10^16
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    int N;
    cin >> N;
    vector<int> a(N+1);
    a[0] = 0;
    char tmp;
    for (int i = 1; i < N+1; i++)
    {
        cin >> tmp;
        if(tmp == '#'){
            a[i] = a[i-1] + 1;
        }
        else{
            a[i] = a[i-1];
        }
    }
    int ans = 1000000;
    for (int k = 0; k < N+1; k++)
    {
        ans = min(ans, N-k-a[N]+2*a[k]);
    }
    printf("%d\n", ans);


}
