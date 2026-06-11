#include <bits/stdc++.h>
using namespace std;

int main(){ 
    int n;
    cin >> n;
    double ans=0;
    for(int i=0;i<n;i++){
        double a;
        string b;
        cin >> a >> b;
        if(b == "JPY")ans +=a;
        else ans += a*380000;
    }
    cout << ans << endl;

}