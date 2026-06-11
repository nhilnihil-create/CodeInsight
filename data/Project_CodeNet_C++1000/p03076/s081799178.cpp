#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int a[15];

int main()
{
    _FastIO;
    int ans = 0;
    int m = 10;
    for(int i = 0; i < 5; i++){
        cin >> a[i];
        ans += a[i];
        if(a[i] % 10){
            m = min(m , (a[i] % 10));
            ans += (10 - (a[i] % 10));
        }
        
    }
    if(m != 10){
      ans -= 10;
        ans += m;  
    }
    
    cout << ans << endl; 
    return 0;
}
