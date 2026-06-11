#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main(){
    int N;
    cin >> N;
    int a[N];
    for(int i = 0; i < N; i++) cin >> a[i];

    ll ans = 0;
    int x = 0;
    for(int i = N - 1; i >= 0; i--){
        if(x == a[i]){
            x--;
        }
        else if(x < a[i]){
            ans += a[i];
            x = a[i] - 1;
        }
        else{
            cout << -1 << endl;
            return 0;
        }
    }

    if(x != -1) ans = -1;

    cout << ans << endl;
    return 0;
}