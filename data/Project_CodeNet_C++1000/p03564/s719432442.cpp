#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)

int main(){
    int n,k,ans;
    cin >> n >> k;
    ans = 1;
    for (int i = 0;i < n;i++){
        ans = min(ans+k,2*ans);
    }
    cout << ans << endl;

     

    return 0;

}
