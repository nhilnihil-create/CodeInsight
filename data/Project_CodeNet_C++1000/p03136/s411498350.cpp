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
    
    int N;
    io.read(N);
    vector<int> L(N);
    for(int i = 0; i < N; i++){
        io.read(L[i]);
    }
    string ans = "Yes";
    for(int i = 0; i < N; i++){
        int sum = 0;
        for(int j = 0; j < N; j++){
            if(i != j) sum += L[j];
        }
        if(L[i] >= sum) ans = "No";
    }
    cout << ans;
    return 0;
}