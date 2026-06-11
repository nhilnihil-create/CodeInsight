#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    int ans=1;
    int com=1;
    for(int i=0;i<n;i++){
        cin >> a[i];
        ans*=3;
        if(a[i]%2==0){
            com*=2;
        }
    }
    cout << ans-com << endl;
}