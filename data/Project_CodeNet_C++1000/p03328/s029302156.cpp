#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstdlib>
#include<set>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

#include<iostream>

int main(){
    int a, b;
    cin >> a >> b;
    int sm[999];
    rep(i, 999) sm[i] = 0;
    sm[0] = 1;
    rep(i, 998) sm[i+1] += sm[i] + i + 2;
    // rep(i, 20) cout << sm[i] <<endl;
    int idx = b - a;
    cout << sm[idx-1] - b << endl;
}