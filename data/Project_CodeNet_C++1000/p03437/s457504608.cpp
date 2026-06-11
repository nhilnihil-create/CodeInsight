#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;

const int INT_INF = 2147483646;
const ll LL_INF = 9223372036854775807;


const int SIZE = 1e5+100;
ll x,y;

int main(){
    cin >> x >> y;

    if(x % y == 0){
          cout << "-1\n";
        return 0;
    }
    

    cout << x*(y-1) << endl;
}