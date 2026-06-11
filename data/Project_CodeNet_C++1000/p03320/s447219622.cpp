#include <bits/stdc++.h>

using namespace std;

#define DEBUG(...) fprintf(stderr,__VA_ARGS__)

#define rep(i , l , r) for(int i = (l) , ___ = (r) ; i <= ___ ; ++i )
#define per(i , r , l) for(int i = (r) , ___ = (l) ; i >= ___ ; --i )

// using LL = long long;
// using uLL = unsigned long long;
typedef long long LL;
typedef unsigned long long uLL;

const int Mod = 998244353;
const LL INF = 1e18;

template<typename T>inline bool chkmin(T &x , const T &y) { return x > y ? (x = y , 1) : 0; }
template<typename T>inline bool chkmax(T &x , const T &y) { return x < y ? (x = y , 1) : 0; }

template<typename T>inline T read(T &f)
{
    f = 0; int x = 1 ; char c = getchar();
    while(!isdigit(c)) x = (c == '-' ? -1 : 1) , c = getchar();
    while(isdigit(c)) (f *= 10) += c & 15 , c = getchar();
    return f = x * f;
}
// template<typename T , typename ... Args>inline void read(T &x , Args&& ... y) { read(x) , read(y...); }

vector<LL> Ans; vector<double> val;
int k , len ; LL res;

int sum(LL x)
{
    int res = 0;
    while(x)
    {
        res += x % 10;
        x /= 10;
    }
    return res;
}

int main()
{
    read(k);
    for(len = 1 , res = 1 ; len <= 14 ; len++ , res *= 10)
    {
        rep(j , 1 , 9999)
        {
            Ans.push_back((j + 1) * res - 1) , val.push_back(0);
        }
    }
    sort(Ans.begin() , Ans.end()) , unique(Ans.begin() , Ans.end());
    val[Ans.size()] = INF * 1.0;
    per(i , Ans.size() - 1 , 0)
    {
        val[i] = 1.0 * Ans[i] / sum(Ans[i]);
        if(val[i] > val[i + 1]) Ans[i] = 0;
        chkmin(val[i] , val[i + 1]);
    }
    for(int i = 0 ; k ; i++)
    if(Ans[i]) printf("%lld\n" , Ans[i]) , k--;
    return 0;
}

