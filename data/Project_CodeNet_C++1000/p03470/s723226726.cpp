#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    int d[110];
    cin >> n;
    
    for(int i=0;i<n;i++)cin >> d[i];
    sort(d,d+n,greater<int>());
    
    int ans = 1;
    
    for(int i=0;i<n-1;i++){
        if(d[i]>d[i+1]) ans++;
    }
    
    cout << ans;
}
