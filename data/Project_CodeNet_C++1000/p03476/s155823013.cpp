#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <functional>
#include <bitset>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <numeric>
#include <iomanip>
#define ll long long int
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int mx4[] = {0,1,0,-1};
int my4[] = {1,0,-1,0};
ll MOD = 1e9 + 7;
 
int y[100004],Y[100004],b[100004];

int main() {
    int q;
    cin >> q;
    for(int i = 1; i <= 100000; i++){
        int k = 100000/i;
        for(int j = 1; j <= k; j++){
            y[i*j]++;
        }
    }
    for(int i = 3; i <= 100000; i+=2){
        if(y[i] == 2 && y[(i+1)/2] == 2) {
            Y[i]++;
            b[i]++;
        }
    }
    //rep(i,100) if(Y[i]==1) cout<<i<<endl;

    for(int i = 0; i < 100000; i++) Y[i+1] += Y[i];
    
    for(int i = 0; i < q; i++){
        int l,r; 
        cin >> l >> r;
        int ans = Y[r] - Y[l];
        if(b[l] == 1) ans++;
        cout << ans << endl;       
    }
}