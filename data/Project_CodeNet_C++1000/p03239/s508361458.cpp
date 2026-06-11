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

int main(){
    Stream io;
    
    int N, T;
    io.read(N, T);
    vector<int> c(N);
    vector<int> t(N);
    for(int i = 0; i < N; i++){
        io.read(c[i], t[i]);
    }
    int ans = 10000;
    for(int i = 0; i < N; i++){
        if(t[i] <= T) ans = min(ans, c[i]);
    }
    if(ans == 10000) cout << "TLE";
    else cout << ans;
    return 0;
}