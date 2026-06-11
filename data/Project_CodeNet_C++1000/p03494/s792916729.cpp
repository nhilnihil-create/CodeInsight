#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    int n; cin>>n;

    int ans=1e9;
    while(n--){
        int a; cin>>a;
        int count_2 = 0;
        while(a%2 == 0){
            count_2++;
            a /= 2;
        }
        ans = min(ans,count_2);
    }
    cout << ans << endl;

}
