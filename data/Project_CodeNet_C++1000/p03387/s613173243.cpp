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
    
    int A, B, C;
    io.read(A, B, C);
    vector<int> v = {A, B, C};
    sort(v.begin(), v.end());
    int ans;
    if(v[0] == v[1] && v[0] == v[2]){
        ans = 0;
    }
    else if(v[0] == v[1]){
        ans = v[2] - v[0];
    }
    else{
        ans = 0;
        if(v[1] != v[2]){
            ans += v[2] - v[1];
            v[0] += v[2] - v[1];
            v[1] = v[2];
        }
        ans += ((v[1] - v[0]) + (v[1] - v[0]) % 2) / 2;
        v[0] += (v[1] - v[0]) + (v[1] - v[0]) % 2;
        if(v[0] > v[1]) ans++;
    }
    cout << ans;
    return 0;
}