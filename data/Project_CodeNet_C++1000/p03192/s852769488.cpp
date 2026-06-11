#include <bits/stdc++.h>
using namespace std;
#define repr(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

int main(){
    string n;
    cin >> n;
    int ans=0;
    for(int i=0;i<n.length();i++){
        if(n[i]=='2') ans++;
    }
    
    cout << ans << endl;
    
    return 0;
}


