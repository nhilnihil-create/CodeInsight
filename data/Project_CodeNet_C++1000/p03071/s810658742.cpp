#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;

int main(){
    int a,b;
    cin >> a >> b;
    int ans = 0;
    ans = max(2*a-1,2*b-1);
    ans = max(ans,a+b);
    cout << ans << endl;    
}