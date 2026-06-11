#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    int l[110];
    cin >> n;
    for(int i=0;i<n;i++)cin >> l[i];
    
    sort(l,l+n,greater<int>());
    
    int other = 0;
    
    for(int i=1;i<n;i++){
        other+=l[i];
    }
    
    if(l[0]>=other) cout << "No";
    else cout << "Yes";
    
    return 0;
}
