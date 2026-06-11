#include <bits/stdc++.h>

#define tc(t) int t; cin>>t; while(t--)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    if(a<=5){
        cout << "0" <<"\n";
    }
    else if (a >=6 && a <=12){
        cout << b/2 <<"\n";
    }
    else{
        cout << b << "\n";
    }


}




