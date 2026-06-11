#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    int n; cin >> n;
    if(n%10==0){
        cout << 10 << endl;
        return 0;
    }
    int ans=0;
    while(n>0){
        ans += n%10;
        n /= 10;
    }
    cout << ans << endl;
    return 0;
}
