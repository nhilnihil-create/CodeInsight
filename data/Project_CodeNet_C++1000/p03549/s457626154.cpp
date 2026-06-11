#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)
const ll mod = 1e9+7;

int main(){
    int n,m;
    cin >> n >> m;
    int ans=0;
    ans=1900*m+100*(n-m);
    ans*=1 << m;
    cout << ans << endl;

     return 0;
}
