#include<bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define INF 10000000000000000LL
#define ll  long long 
const int inf =INT_MAX;
const int MAX=3e5+9;
const ll MOD=1e9+7;
const int TOT_PRIMES=1e6+9;
const int MAX_A=71;
const int LN=20;
using namespace std;

int main(){
    int N; cin >> N;

    while(N > 0){
        if(N % 4 == 0){
            cout << "Yes" << "\n";
            return 0;
        }
        N -= 7;
    }
    if(N == 0)
        cout << "Yes" << "\n";
    else
        cout << "No" << "\n";
    return 0;
}