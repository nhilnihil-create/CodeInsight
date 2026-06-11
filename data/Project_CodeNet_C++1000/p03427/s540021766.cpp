#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ll N,ans = 0;
    cin >> N;
    string tmp = to_string(N);
    if(tmp.size() == 1){
        ans = (tmp[0] - '0');
        cout << ans << endl;
        return 0;
    }
    ans += (tmp[0] - '0') + (tmp.size() - 1) * 9;
    if(N % 10 == 9){
        cout << ans << endl;
    }else{
        cout << ans - 1 << endl;
    }
    
}
