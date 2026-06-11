#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)


int main(){
    int n,m;
    cin >> n >> m;
    if (n == 1) cout << 1900*2 << endl;
    else{
        ll ans;
        ans = 1900*m+ (n-m)*100 ;
        ll now = 1;
        while(m--){
            now*=2;
        }
        cout << ans*now << endl;
    }
    

    return 0;
}