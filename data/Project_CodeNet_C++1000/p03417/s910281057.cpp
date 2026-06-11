#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<tuple>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<math.h>
using namespace std;
using ll = int64_t;
using Graph = vector<vector<int> >;
const ll M = 1000000007;

int main(){
    ll n,m;
    cin >> n >> m;

    if(n>=3 && m>=3) {
        cout << (n-2)*(m-2) << endl;
        return 0;
    }

    if(n==2 || m==2) {
        cout << 0 << endl;
        return 0;
    }

    if((n==1 || m==1) && (n>=3 || m>=3)){
        if(n==1) cout << m-2 << endl;
        if(m==1) cout << n-2 << endl;
        return 0;
    }

    if(n==1 && m==1){
        cout << 1 << endl;
        return 0;
    }
}