#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)

int table[101][101];



int main(){
    int n;
    cin >> n;
    int ans = 0;
    for (int i= 1;i*i <= n;i++){
        if ( i*i <= n);
        ans = max(ans,i*i);
    }
    cout << ans << endl;


    return 0;
}