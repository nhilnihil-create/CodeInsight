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
    
    int Q;
    io.read(Q);
    vector<int> l(Q);
    vector<int> r(Q);
    for(int i = 0; i < Q; i++){
        io.read(l[i], r[i]);
    }
    vector<int> v(100001, 1);
    v[0] = v[1] = 0;
    for(int i = 2; i < v.size(); i++){
        if(v[i] == 0) continue;
        for(int j = 2 * i; j < v.size(); j += i){
            v[j] = 0;
        }
    }
    for(int i = v.size() - 1; i >= 0; i--){
        if(v[(i + 1) / 2] == 0) v[i] = 0;
    }
    for(int i = 0; i < v.size() - 1; i++){
        v[i + 1] += v[i];
    }
    for(int i = 0; i < Q; i++){
        cout << v[r[i]] - v[l[i] - 1] << '\n';
    }
    return 0;
}