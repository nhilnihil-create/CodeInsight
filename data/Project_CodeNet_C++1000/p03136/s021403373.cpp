#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,ans=0;
    cin >> n;
    int l[n];
    for(int i=0;i<n;i++){
        cin >> l[i];
    }
    sort(l,l+n);
    for(int i=0;i<n-1;i++){
        ans = ans + l[i];
    }
    if(ans>l[n-1]) cout << "Yes" << endl;
    else cout << "No" << endl;
}