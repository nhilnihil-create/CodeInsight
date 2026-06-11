#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<string>
#include<utility>
#include<numeric>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;

using ll = long long;

class Stream{
public:
    Stream(){

    }
    //配列以外の入力を受け取る
    void read(){

    }
    template<typename First, typename... Rest>
    void read(First& first, Rest&... rest){
        cin >> first;
        read(rest...);
    }
    template<typename T>
    vector<T> read_vec(size_t n){
        vector<T> tmp(n);
        for(size_t i = 0; i < n; i++){
            cin >> tmp[i];
        }
        return tmp;
    }
    //配列を区切って出力する
    template<typename T>
    void write_vec(vector<T>& v, char divider){
        for(size_t i = 0; i < v.size(); i++){
            cout << v[i] << divider;
        }
    }
};

void prime_factor(int n, map<int, int>& mp){
    for(int i = 2; i * i <= n; i++){
        int k = 0;
        while(n % i == 0) n /= i, k++;
        if(k > 0) mp[i] += k;
    }
    if(n > 1) mp[n]++;
}

int main(){
    Stream io;
    
    int N;
    io.read(N);
    map<int, int> mp;
    for(int i = 2; i <= N; i++){
        prime_factor(i, mp);
    }
    vector<vector<int>> dp(mp.size() + 1, vector<int>(76, 0));
    dp[0][1] = 1;
    int i = 1;
    for(auto& x : mp){
        for(int j = 1; j <= 75; j++){
            for(int k = 0; k <= x.second; k++){
                if((k + 1) * j <= 75) {
                    dp[i][(k + 1) * j] += dp[i - 1][j];
                }
            }
        }
        i++;
    }
    cout << dp[mp.size()][75];
    return 0;
}
