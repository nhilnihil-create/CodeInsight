#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long double ans=0;
    long double x;
    string S;
    for(int i=0;i<n;i++){
        cin >> x >> S;
        if(S=="JPY")ans+=x;
        else ans += 380000.0*x;
    }
    cout << fixed << setprecision(16);
    cout << ans << endl;
}