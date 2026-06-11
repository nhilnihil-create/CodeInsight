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
    
    string S1;
    string S2;
    io.read(S1, S2);
    string ans = "YES";
    for(int i = 0; i < S1.size(); i++){
        if(S1[i] != S2[S1.size() - i - 1]){
            ans = "NO";
        }
    }
    cout << ans;
    return 0;
}