
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
#define ll long long
const int inf = 1000000000;

int main(){
    vector<int> a(5);
    cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
    vector<int> p={0,1,2,3,4};
    int ans2=inf;
    do{
        int ans = 0;
        for(int i=0;i<5;i++){
            while(ans%10!=0)ans++;
            ans += a[p[i]];
        }
        ans2 = min(ans2,ans);
    }while(next_permutation(p.begin(),p.end()));
    cout << ans2 << endl;
    return 0;
}