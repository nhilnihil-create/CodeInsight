#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

vector<pair<long long, long long> > prime_factorize(long long n) {
    vector<pair<long long, long long> > res;
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) { ++num; n /= p; }
        res.push_back(make_pair(p, num));
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    return res;
}

int main(){
    int n;
    cin>>n;
    map<int,int> sm;
    for(int i=1;i<=n;i++){
        auto pf=prime_factorize(i);
        for(auto p : pf) sm[p.first]+=p.second;
    }

    int ans=0;
    for(int a=2;a<=n;a++){
        if(74<=sm[a]) ans++;
    }

    for(int a=2;a<=n;a++){
        for(int b=2;b<=n;b++){
            if(a!=b && sm[a]>=14 && sm[b]>=4) ans++; 
        }
    }

    for(int a=2;a<=n;a++){
        for(int b=2;b<=n;b++){
            if(a!=b && sm[a]>=24 && sm[b]>=2) ans++; 
        }
    }

    for(int a=2;a<=n;a++){
        for(int b=2;b<=n;b++){
            for(int c=b+1;c<=n;c++){
                if(a!=b && a!=c && sm[a]>=2 && sm[b]>=4 && sm[c]>=4) ans++; 
            }
        }
    }

    cout<<ans<<endl;
}