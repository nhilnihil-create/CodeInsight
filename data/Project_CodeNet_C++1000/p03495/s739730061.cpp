#include<bits/stdc++.h>
using namespace std;
int main(){
   int cut[20000001];
   int n,k;
   cin >> n >>k;
   for(int i=0;i<n;i++){
       int a;
       cin >> a;
       cut[a-1]++;
    }
    sort(cut,cut+n);
    int ans=0;
    for(int i=0;i<n-k;i++){
        ans += cut[i];

    }
    cout << ans << endl;
}