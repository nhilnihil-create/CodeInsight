#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
const int mx = 200005;
int n, a[mx], l, r = mx;

int main(){
    scanf("%d", &n);
    rep(i,n) scanf("%d", a+i);
    while(l+1 < r){
        int mid = (l+r) / 2, hight = 0;
        bool ok = true;
        map<int, int> mp;
        rep(i,n){
            if(hight < a[i]) hight = a[i];
            else{
                if(mid == 1){
                    ok = false; break;
                }
                hight = a[i];
                while(++mp[hight] >= mid && hight > 0) hight--;
                if(hight == 0){
                    ok = false;
                    break;
                }
            }
            mp.erase(mp.upper_bound(hight), mp.end());
        }
        (ok ? r : l) = mid;
    }
    printf("%d\n", r);
}