#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    int a, b, k;
    cin >> a >> b >> k;

    vector<int> w(0);
    for(int i = 1; i <= min(a,b); i++) if(a%i == 0 && b%i == 0) w.push_back(i);
    reverse(all(w));

    cout << w[k-1] << endl;

    return 0;
}