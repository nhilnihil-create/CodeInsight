#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0;i<n;++i)
#define all(v) v.begin(), v.end()
#define PI 3.141592653589793238462643383279
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
typedef long long int ll;
typedef unsigned long long ull;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
typedef pair<ll,ll> P;
const long long MOD = 1e9+7;
const ll INF = 1LL << 60;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int vector_finder(std::vector<int> vec, int number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return 1;
  }
  else { // 発見できなかったとき
    return 0;
  }
}

int main(){
    int n; //n:スイッチの個数
    int m; //m:電球の個数

    cin >> n >> m;
    int ans = 0;

    vector<vector<int>> data(m);

    for(int i = 0; i < m; i++){
        int k; cin >> k;
        for(int j = 0; j < k; j++){
            int a; cin >> a; a--;
            data[i].push_back(a);
        }
    }

    vector<int>check(m);
    for(int i = 0; i < m; i++){
        cin >> check[i];
    }

    for(int i = 0; i < (1 << n); i++){
        bool flag = true;
        bitset<10> bs(i);
        
        for(int j = 0; j < m; j++){ //電球をそれぞれ見ていく！
            int on = 0;

            for(int l = 0; l < n; l++){
                if(((i >> l) & 1) == 1 && vector_finder(data[j],n-l-1) == 1){
                    on++;
                    
                }
            }
            if(flag){
                if(!(on % 2 == check[j]))flag = false;
            }
       }
       if(flag)ans++;
    }

    cout << ans << endl;

}
