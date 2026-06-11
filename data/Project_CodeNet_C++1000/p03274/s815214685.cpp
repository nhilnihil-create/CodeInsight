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
    //配列を区切って出力する
    template<typename T>
    void write_vec(vector<T>& v, char divider){
        for(size_t i = 0; i < v.size(); i++){
            cout << v[i] << divider;
        }
    }
}; 

int dist(int lv, int rv){
    return min(abs(lv), abs(rv)) + abs(rv - lv);
}

int main(){
    Stream io;
    
    int N, K;
    io.read(N, K);
    vector<int> x(N);
    for(int i = 0; i < N; i++){
        io.read(x[i]);
    }

    int ans = dist(x[0], x[K - 1]);
    for(int l = 1, r = K; r < N; l++, r++){
        ans = min(ans, dist(x[l], x[r]));
    }
    cout << ans;
    return 0;
}