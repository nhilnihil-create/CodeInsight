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

    int N, M;
    io.read(N, M);
    vector<int> K(N);
    vector<vector<int>> A(N);
    for(int i = 0; i < N; i++){
        io.read(K[i]);
        A[i].resize(K[i]);
        for(int j = 0; j < K[i]; j++){
            io.read(A[i][j]);
        }
    }
    map<int, int> mp;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < K[i]; j++){
            mp[A[i][j]]++;
        }
    }
    int ans = 0;
    for(auto i = mp.begin(); i != mp.end(); i++){
        if(i->second == N) ans++;
    }
    io.write(ans);
    return 0;
}