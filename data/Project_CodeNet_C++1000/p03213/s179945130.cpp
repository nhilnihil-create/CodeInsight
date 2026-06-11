#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
const long long MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
// cout << fixed << setprecision(10) << ans << endl; 有効桁数指定
// *min_element(c + l, c + r) *max_element(c + l, c + r) 配列の中のmin-max
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// ~ は、-1の時だけfalse

long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

long long LCM(long long a, long long b) {
    return a / GCD(a, b) * b;
}

// ax + by = gcd(a, b) となるような (x, y) を求める
// 多くの場合 a と b は互いに素として ax + by = 1 となる (x, y) を求める
long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    // 再帰的に解く (x, y を入れ替えておく)
    long long d = extGCD(b, a % b, y, x); 
    y -= a / b * x;
    return d;
}

// 素因数分解
vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0;
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        res.push_back({a, ex});
    }
    if (N != 1) res.push_back({N, 1});
    return res;
}

//約数列挙
vector<long long> enum_divisors(long long N) {
    vector<long long> res;
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            // 重複しないならば i の相方である N/i も push
            if (N/i != i) res.push_back(N/i);
        }
    }
    // 小さい順に並び替える
    sort(res.begin(), res.end());
    return res;
}

ll vec[110];

int main () {

    ll n;cin>>n;
    
    for (ll i =2;i<=n;i++) {
        const auto &pf = prime_factorize(i);
        for(auto p:pf) {
            vec[p.first]+=p.second;
        }
    }

    ll ans=0;
    ll num_75=0,num_25=0,num_15=0,num_5=0,num_3=0;
    rep(i,110) {
        if (vec[i]>=74)  {
            num_75++;
            num_25++;
            num_15++;
            num_5++;
            num_3++;
        } else if (vec[i]>=24) {
            num_25++;
            num_15++;
            num_5++;
            num_3++;
        } else if (vec[i]>=14) {
            num_15++;
            num_5++;
            num_3++;
        } else if (vec[i]>=4) {
            num_5++;
            num_3++;
        } else if (vec[i]>=2) {
            num_3++;
        }
    }

    // cout<<num_75<<" "<<num_25<<" "<<num_5<<" "<<num_3<<endl;

    ans+=num_75+num_25*(num_3-1)+num_5*(num_5-1)/2*(num_3-2)+num_15*(num_5-1);

    cout<<ans<<endl;

}