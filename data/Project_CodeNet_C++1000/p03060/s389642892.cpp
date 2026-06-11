#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
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
    //配列以外を出力する
    void write(){

    }
    template<typename First, typename... Rest>
    void write(First first, Rest... rest){
        cout << first << " ";
        write(rest...);
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
    int N;
    io.read(N);
    vector<int> V(N);
    vector<int> C(N);
    for(int i = 0; i < N; i++){
        io.read(V[i]);
    }
    for(int i = 0; i < N; i++){
        io.read(C[i]);
    }
    vector<int> sub(N);
    for(int i = 0; i < N; i++){
        sub[i] = V[i] - C[i];
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        if(sub[i] > 0) ans += sub[i];
    }
    io.write(ans);
    return 0;
}