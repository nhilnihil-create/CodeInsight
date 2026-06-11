#include <iostream>
#include <cmath>
#include <string.h>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define INF 100000000;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
int main(){
    int n;
    cin >> n;
    int c[500],s[500],f[500];
    rep(i,n) cin >> c[i] >> s[i] >> f[i];

    rep(i,n){
        int thisans = 0;
        for(int j = i; j < n - 1; j++){
            if(thisans < s[j]) thisans = s[j];
            else if(thisans % f[j] == 0);
            else thisans += f[j] - thisans % f[j];
            thisans += c[j];
        }
        cout << thisans << endl;
    }
}