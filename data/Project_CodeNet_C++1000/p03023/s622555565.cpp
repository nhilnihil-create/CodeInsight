#include <iostream>
#include <stdlib.h>
#include <vector> //vector
#include <algorithm> //sort()
#include <numeric>

#define rep(i, n) for(int i=0; i<(int)(n);i++)
#define all(x) (x).begin(), (x).end()
#define debug(a) cout << "debug (" #a "):" << endl << (a) << endl;

typedef uint64_t ulint;
typedef int64_t lint;

using namespace std;

template<class T> inline bool chmin(T& a, T b);
template<class T> inline bool chmax(T& a, T b);
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v);

template<class T> lint sum(vector<T> a);
template<class T> double ave(vector<T> a);

//uint64_t a, b, c, d;
//uint64_t i, j;
lint n, m;

int main(){
//////////////////////////////////////////////////////

    cin >> n;

    cout << (int)((180.0 - (double)(360.0 / n)) * n) << endl;

    // vector<lint> a( n );
    // vector<lint> b( m );
    // vector<lint> c( m );

    // for ( lint i = 0 ; i < n ; i ++)
    // {
    //     cin >> a[i];
    // }

    // for ( lint i = 0 ; i < m ; i ++)
    // {
    //     cin >> b[i] >> c[i];
    // }
    // //debug(a);
    // rep(i,m)
    // {
    //     sort(all(a));
    //     rep(j , b[i])
    //     {
    //         if(a[j]<c[i])
    //         {
    //             a[j]=c[i];
    //         }
    //         else
    //         {
    //             break;
    //         }
            
            
    //     }
    //     //debug(a);

    // }

    //昇順ソート
    //sort(all(a));


    //デバッグ出力
    //debug(a);
    //debug(b);
    //debug(c);

    // ulint sum=0;
    // rep(i,n)
    // {
    //     sum += a[i];
    // }

    // cout << sum << endl;

    

   

    // sort(input.begin() , input.end());

    // uint64_t max = numeric_limits<uint64_t>::max();


    //////////////////////////////////////////////////////
    // DP

//     // 無限大の値
//     const uint64_t INF = (uint64_t)1 << 60;
//     //const int64_t NINF = -1 * ((int64_t)1 << 60 );
 
//     // DP テーブル
//     uint64_t dp[100010];

//     //DPテーブル初期化（最小化用）
//     for (int i = 0; i < 100010; ++i)
//     {
//         //dp[i] = INF;
//         dp[i] = 0;
//     } 

//     // 初期条件
//     dp[0] = 0;

//     // ループ
//     for (int i = 1; i <= n; ++i) {
//         //chmin( dp[i], dp[i - 1] + abs( input[i] - input[i - 1] ));
//         //if (i < 2)continue;
//         //chmin( dp[i], dp[i - 2] + abs( input[i] - input[i - 2] ));



//         // chmax ( dp [i] , dp[i - 1]);
//         // chmax ( dp [i] , dp[i - 1] + input[i]);
//         // cout << "dp[" << i <<"] = " << dp[i] << endl;

//     }



// //////////////////////////////////////////////////////

//     cout << dp[n] << endl;

//////////////////////////////////////////////////////
// Ctrl + Opt + N to make
    return 0;
}


//最小化用関数
template<class T> inline bool chmin(T& a, T b)
{
    if (a > b) 
    {
        a = b;
        return true;
    }
    return false;
}

//最大化関数
template<class T> inline bool chmax(T& a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}


// vectorprint用
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
	int len = v.size();
	for (int i = 0; i < len; ++i) {
		s << v[i]; if (i < len - 1) s << "\t";
	}
	return s;
}

// //合計
// template<class T> lint sum(vector<T> a)
// {
//     return std::accumulate(a.begin(), a.end(), 0);
// }


// //平均
// template<class T> double ave(vector<T> a)
// {
//     return std::accumulate(a.begin(), a.end(), 0.0) / a.size();
// }
