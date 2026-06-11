#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'

int main(){
    int n, a, b;
    cin >> n >> a >> b;
    int ans=0;
    for(int i=0; i<=n; ++i){
        int sum, x = i;
        for(sum=0; x>0; sum+=x%10, x/=10);

        if(sum <= b && sum>=a)
            ans += i;
    }
    cout << ans;
}
