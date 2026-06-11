#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < int(n);i++)

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    rep(i,n) cin >> v[i];
    cout << (n-3 + k)/ (k-1) << endl;
    return 0;

}
