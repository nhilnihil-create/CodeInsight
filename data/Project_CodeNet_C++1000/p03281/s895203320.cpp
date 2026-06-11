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

int countDivisors(int n) 
{ 
    int cnt = 0; 
    for (int i = 1; i <= sqrt(n); i++) { 
        if (n % i == 0) { 
            // If divisors are equal, 
            // count only one 
            if (n / i == i) 
                cnt++; 
            else // Otherwise count both 
                cnt = cnt + 2; 
        } 
    } 
    return cnt; 
}

int main(){
    int N; cin >> N;
    int cnt, cnt8 = 0;
    if( N < 105){
        cout << 0 << "\n";
        return 0;   
    }
    for(int i = 107; i <= N; i += 2){
        cnt = countDivisors(i);
        if(cnt == 8)
            cnt8++;
    }
    cout << cnt8 + 1 << "\n";
    return 0;
}