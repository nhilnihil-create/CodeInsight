#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;


struct Linear_Sieve{
int n;
vector<int> lp,primes;
//lp[i]...the least prime of i. primes...prime numbers
Linear_Sieve(int n = 1):n(n),lp(n+1){
    for(int i = 2;i < n+1;i++){
        if(lp[i] == 0) {
            primes.push_back(i);
            lp[i] = i;
        }
        for(int j = 0;j<primes.size() && primes[j] <= lp[i] && i*primes[j] < n+1; ++j) lp[i*primes[j]] = primes[j];
    }
}
bool isPrime(int x) {return lp[x] == x;}

vector<int> factorList(int x){
    //make list which contains prime factors of x. Ans it toralates multipled components.
    vector<int> res;
    while(x != 1){
        res.push_back(lp[x]);
        x /= lp[x];
    }
    return res;
}

vector<pair<int,int>> factor(int x){
        //make list of pairs which couple prime factor and multiplicity.
    vector<int> fl = factorList(x);
    if(fl.size() == 0) return{};
    vector<pair<int,int>> res(1,pair<int,int>(fl[0],0));
    for(int p : fl){
        if(res.back().first == p){
            res.back().second++;
        }else{
            res.emplace_back(p,1);
        }
    }
    return res;
}
};

int main(){
    int q;cin >> q;
    Linear_Sieve s(100009);
    vector<int> num(100009,0);
    for(int i = 3;i<=100001;i+=2){
        if(i==3){
            num[i] = 1;
            continue;
        }
        if(s.isPrime(i) && s.isPrime((i+1)/2)) num[i] = num[i-2] + 1;
        else num[i] = num[i-2];
    }
    //rep(i,10) cout << num[i] << endl;
    rep(i,q){
        int l,r;
        cin >> l >> r;
        cout << num[r] - num[max(l-2,1)] << endl;;
    }
    

}