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
    vector<int> A(N);
    vector<int> B(N);
    for(int i = 0; i < N; i++){
        io.read(A[i], B[i]);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; 
    for(int i = 0; i < N; i++){
        q.push(make_pair(A[i], B[i]));
    }
    ll ans = 0;
    while(M > 0){
        pair<int, int> p = q.top();
        q.pop();
        ll x = min(M, p.second);
        ans += p.first * x;
        M -= x;
    }
    io.write(ans);
    return 0;
}