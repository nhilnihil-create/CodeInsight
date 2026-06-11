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

const int MAX_N = 1000000;
#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define prec std::cout << std::fixed << std::setprecision(15);
#define endl "\n"
#define MOD 1000000007
#define Int int64_t
#define PI 3.14159265358979
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define ssort(z) sort(z.begin(), z.end())
#define rsort(z) sort(z.rbegin(), z.rend())
#define eerase(z) z.erase(unique(z.begin(), z.end()), z.end())
#define ccnt(z, w) count(z.begin(), z.end(), w)
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

void y() {
    cout << "Yes" << endl;
    exit(0);
}

void n() {
    cout << "No" << endl;
    exit(0);
}

void Y() {
    cout << "YES" << endl;
    exit(0);
}

void N() {
    cout << "NO" << endl;
    exit(0);
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

/*   kokomade  */

int cnt = 0;
bool is_prime[ 50000 + 1 ];
vector<int> P;
void Eratosthenes( const int N )
{
    for( int i = 0; i <= N; i++ )
    {
        is_prime[ i ] = true;//初期化
    }
    for( int i = 2; i <= N; i++ )
    {
        if( is_prime[ i ] )
        {
            for( int j = 2 * i; j <= N; j += i )
            {
                is_prime[ j ] = false;
            }
            P.emplace_back( i );
        }
    }
}

int main() {
    IOS;
    int n,a,b;
    Int ans=0;
    cin>>n>>a>>b;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin>>p[i];
    }
    int cnt1=0,cnt2=0,cnt3=0;
    for (int j = 0; j < n  ; ++j) {
        if(p[j]<=a)cnt1++;
        else if(p[j]<=b) cnt2++;
        else cnt3++;
    }
    ans=min({cnt1,cnt2,cnt3});


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
