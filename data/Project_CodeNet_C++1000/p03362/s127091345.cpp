#include <bits/stdc++.h>
using namespace std;

/*
エラトステネスの篩
*/
// 型定義
typedef long long ll;
typedef pair<ll, ll> P;

// forループ
#define REP(i,n) for(ll i=0; i<(ll)(n); ++i)

// 定数宣言
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

// グラフ表現
using Graph = vector<vector<int>>;

// グラフの辺表現
using Edge = map<pair<int,int>,int>;

// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

// 最大公約数
ll gcd(ll a,ll b){
   if (a%b == 0) return(b);
   else return(gcd(b, a%b));
}

// 最小公倍数
ll lcm(ll a, ll b){
    return a*b/gcd(a, b);
}

ll N;
ll arr[100000];
vector<ll> prime;
void Eratosthenes(){
	for(int i = 0; i < N; i++){
		arr[i] = 1;
	}
	for(int i = 2; i < sqrt(N); i++){
		if(arr[i]){
			for(int j = 0; i * (j + 2) < N; j++){
				arr[i *(j + 2)] = 0;
			}
		}
	}

	for(int i = 2; i < N; i++){
		if(arr[i]){
			//cout << i << endl;
            prime.push_back(i);
		}
	}
}

int main()
{
    cout << fixed << setprecision(15);
    ll K;
    cin >> K;
    N = 55555;
    
    Eratosthenes();

    ll count = 0;
    for(auto v: prime){
        if(v % 5 == 1){
            count++;
            if(count == K){
                cout << v << endl;
                return 0;
            }
            else{
                cout << v << " ";
            }
        }
    }


    return 0;
}