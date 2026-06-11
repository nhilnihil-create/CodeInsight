#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
//#include <stdio.h>
//#include <stack>
//#include <queue>
//#include <cstdio>
#include <cmath>
#include <iterator>
#include <map>
#include <fstream>
//#include <list>
#include <iomanip>
//#include <stdlib.h>
//#include <cctype>

using namespace std;

#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define prec std::cout << std::fixed << std::setprecision(15);
#define endl "\n"
#define MOD 1000000007
#define Int int64_t
#define PI 3.14159265358979
#define ssort(z) sort(z.begin(), z.end())
#define rsort(z) sort(z.rbegin(), z.rend())
#define eerase(z) z.erase(unique(z.begin(), z.end()), z.end())
#define ccnt(z, w) count(z.begin(), z.end(), w)
#define rep(i,a,n) for(Int (i)=(a); (i)<(n); (i)++)
#define repq(i,a,n) for(Int (i)=(a); (i)<=(n); (i)++)
const int MAX_N = 1000000;
const Int MAX_N_Int = 1000000000000;

template <typename T>
void printV(const std::vector<T>& v, const char * const separator = " ")
{
    if(!v.empty())
    {
        std::copy(v.begin(),
                  --v.end(),
                  std::ostream_iterator<T>(std::cout, separator));
        std::cout << v.back() << "\n";
    }
}


Int gcd(Int a, Int b) {
    return b != 0 ? gcd(b, a % b) : a;
}

Int lcm(Int a, Int b) {
    return a / gcd(a, b) * b;
    //a*bは64bit integer overflow
}

int Max(int a, int b, int c) {
    int temp = max(a, b);
    return max(temp, c);
}

int Min(int a, int b, int c) {
    int temp = min(a, b);
    return min(temp, c);
}

bool integer(double num) {
    return floor(num) == num;
}

Int fact(int num) {
    if (num == 0)
        return 1;
    else
        return num * fact(num - 1);
}

Int yakusu(int n) {
    int cnt = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cnt++;
            if (i * i != n) cnt++;
        }
    }
    return cnt;
}


Int fact_mod(Int n, Int mod) {
    Int f = 1; repq(i,2,n) f = f * (i % MOD) % MOD;
    return f;
}

// 繰り返し二乗法 (modの世界での累乗)
Int mod_pow(Int x, Int n, Int mod) {
    Int res = 1;
    while(n > 0) {
        if(n & 1) res = (res * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}

// 組み合わせ nCr を求める
Int combination_mod(Int n, Int r, Int mod) {
    if(r > n-r) r = n-r;
    if(r == 0) return 1;
    Int a = 1;
    rep(i, 0, r) a = a * ((n-i) % mod) % mod;
    Int b = mod_pow(fact_mod(r, mod), mod-2, mod);
    return (a % mod) * (b % mod) % mod;
}

bool rev(string s){
    string t=s;
    reverse(s.begin(),s.end());
    return s==t;
}
Int w(Int n, Int a){
    return (n+a-1)/a;
}
int main() {
    //COMinit();
    IOS;
    prec;
    Int a=0,b=0,c,d,e,n,m,x,k=1,y=0,ans=0;
    string str,s,t,u;
    cin>>n;
    vector<int>aa(n);
    for (int i = 0; i <n ; ++i) {
        cin>>aa[i];
    }
    int now =aa[0];
    for (int j = 1; j < n; ++j) {
        if(aa[j]==now){
            ans++;
            now=-1;
        }else{
            now=aa[j];
        }
    }
    cout<<ans;











    cout<<endl;
    return 0;
}

/*
テレビも無ェ ラジオも無ェ
自動車もそれほど走って無ェ
ピアノも無ェ バーも無ェ
巡査 毎日ぐーるぐる
朝起ぎで 牛連れで
二時間ちょっとの散歩道
電話も無ェ 瓦斯も無ェ
バスは一日一度来る
俺らこんな村いやだ 俺らこんな村いやだ
東京へ出るだ 東京へ出だなら
銭コァ貯めで 東京でベコ(牛)飼うだ
*/
