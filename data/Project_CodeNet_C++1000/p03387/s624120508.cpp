#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main(){
    std::vector<int> a(3);
    std::cin >> a[0] >> a[1] >> a[2];

    std::sort(a.begin(),a.end());

    int ans = 0;
    while(true){
        if(a[2]-a[1]>1){
            a[1]+=2; ans++;
        }else if(a[1]-a[0]>1){
            a[0]+=2; ans++;
        }else if(a[2]-a[1]>0 && a[1]-a[0]>0){
            a[0]++; a[1]++; ans++;
        }else if(a[2]-a[1]==0 && a[1]-a[0]>0){
            a[2]++; a[1]++; ans++;
        }else if(a[2]-a[1]>0 && a[1]-a[0]==0){
            a[1]++; a[0]++; ans++;
        }else{
            break;
        }
    }

    std::cout << ans << "\n";
    return 0;
}