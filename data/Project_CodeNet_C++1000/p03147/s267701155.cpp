#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> h(n),a(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    int ans=0;
    if(n==1){
        ans = h[0];
    }
    else{
    while(h != a){
       for(int i = 0; i < n-1; i++) {
           if(i==0 && h[0]!=0) {
               ans ++;
               continue;
           }

           if(h[i]==0 && h[i+1] != 0) ans ++;

       } 
       for(int i = 0; i < n; i++) {
           if(h[i]!=0) h[i]--;
       }
    }
    }

    cout << ans << endl;

    return 0;
}