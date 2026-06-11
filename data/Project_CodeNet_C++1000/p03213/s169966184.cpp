#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000009
const long long INF = 1LL<<60;

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

int main() {
    int n;
    cin>>n;
    map<int,int> sm;
    for(int i=1;i<=n;i++){
        auto pf=prime_factorize(i);
        for(auto p : pf) sm[p.first]+=p.second;
    }


    int ans=0;
    for(int i=2;i<=n;i++) if(74<=sm[i]) ans++;
    for(int i=2;i<=n;i++){
        for(int j=2;j<=n;j++){
            if(i!=j && 14<=sm[i] && 4<=sm[j]) ans++;
        }
    } 
    for(int i=2;i<=n;i++){
        for(int j=2;j<=n;j++){
            if(i!=j && 24<=sm[i] && 2<=sm[j]) ans++;
        }
    } 
    for(int i=2;i<=n;i++){
        for(int j=2;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                if(i!=j && i!=k && 2<=sm[i] && 4<=sm[j] && 4<=sm[k]) ans++;
            } 
        }
    } 

    cout<<ans<<endl;

}