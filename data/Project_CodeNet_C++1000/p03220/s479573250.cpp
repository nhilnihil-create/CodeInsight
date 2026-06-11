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
    
    int N, T, A;
    io.read(N, T, A);
    vector<int> H(N);
    for(int i = 0; i < N; i++){
        io.read(H[i]);
    }
    int ans = 1;
    int m = abs(1000 * T - 6 * H[0] - 1000 * A);
    for(int i = 1; i < N; i++){
        int d = abs(1000 * T - 6 * H[i] - 1000 * A);
        if(d < m){
            m = d;
            ans = i + 1;
        }
    }
    cout << ans;
    return 0;
}