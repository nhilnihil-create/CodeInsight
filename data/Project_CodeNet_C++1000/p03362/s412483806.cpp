//ヘッダー
#include<bits/stdc++.h>
using namespace std;

//型定義
typedef long long ll;

//定数
const int INF=1e+9;
const int MOD=1e+9+7;

//REPマクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define REP2(i,a,b) for(ll i=a;i<(ll)(b);i++)
#define REPD2(i,a,b) for(ll i=a;i>(ll)(b);i--)

// 多次元 vector 生成
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

//vectorの扱い
#define ALL(x) (x).begin(),(x).end() //sortなどの引数省略
#define SIZE(x) ((ll)(x).size()) //size
#define MAX(x) *max_element(ALL(x)) //最大値
#define MIN(x) *min_element(ALL(x)) //最小値

// 素数の列挙

vector<int> Eratosthenes( const int N )
{
    vector<bool> is_prime( N + 1 );
    for( int i = 0; i <= N; i++ )
    {
        is_prime[ i ] = true;
    }
    vector<int> P;
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
    return P;
}

int main(){
    int N;
    cin>>N;
    vector<int> prime=Eratosthenes(55555);
    int cnt=0;
    REP(i,prime.size()){
        if(prime[i]%10==1){
            cout<<prime[i];
            if(cnt==N-1){
                cout<<endl;
                return 0;
            }else{
                cout<<" ";
            }
            cnt++;
        }
    }
}