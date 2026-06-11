#include<bits/stdc++.h>

using namespace std;
int main(){
    int n;
    cin >> n;
    int p[n];
    int sum=0,ans=0;
    for(int i=0; i<n; i++){
       cin >> p[i];
       sum = max(sum,p[i]);
       ans+=p[i];
    }
    ans=ans-sum/2;
    cout << ans << endl;
    return 0;
}