#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int nijou(int n){
    ll ans=1;
    for(int i = 0; i < n; i++) {
        ans *= 2;
    }
    return ans;
}

int main() {
    int n,k;
    cin >> n >> k;
    double ans=0;
    int b;
    for(int i = 1; i <= n; i++) {
        int a;
        if(i>=k){
            a=0;
            if(i==1) b=a;
        }
        else{
            int j=0;
            int l=i;
            while(l<k){
                l *= 2;
                j++;
                if(l>=k){
                    a=j;
                }
            }
            if(i==1) b=a;
        }

        ans += nijou(b-a);
    }
    ans /= nijou(b);
    ans /= n;
    cout << fixed << setprecision(12);
    cout << ans << endl;

    return 0;
}