#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <cmath>
#include <numeric>

using ll = long long;
using std::cout;
using std::cin;
using std::endl;

const ll max = 100005;
typedef enum{ UNDEF=0, PRIME, NONP} Prime;

bool is_prime(ll num){
    static Prime prime_table[max] = {NONP,NONP,PRIME,PRIME};
    if(prime_table[num]!=UNDEF){
        return (prime_table[num]==PRIME);
    }
    ll eratos_max = (ll)(std::sqrt(num))+1;
    for(int i=2; i<=eratos_max; i++){
        if(num%i==0){
            prime_table[num] = NONP;
            return false;
        }
    }
    prime_table[num] = PRIME;
    return true;
    
}

int main(){
    ll n,q;
    cin >> n >> q;
    std::string s;
    cin >> s;
    std::vector<ll> l(q),r(q);
    for(int i=0; i<q; i++){
        cin >> l[i] >> r[i];
    }

    std::vector<ll> a(s.size());
    a[s.size()-1] = 0;
    for(int i=0; i<s.size()-1; i++){    // ACACTACG
        if(s[i]=='A' && s[i+1]=='C'){ // 10100100
            a[i] = 1;
        }else{
            a[i] = 0;
        }
    }
    std::vector<ll> sum(s.size()+1);
    sum[0] = 0;
    for(int i=0; i<s.size(); i++){   // 011222333 
        sum[i+1] = sum[i] + a[i];
    }
    for(int i=0; i<q; i++){
        cout << sum[r[i]-1] - sum[l[i]-1] << endl;
    }
    // 12345678
    // ACACTACG
    // 10100100
    // 011222333
    // 3,7
    //   ACTAC
    //   12223
    
    return 0;
}