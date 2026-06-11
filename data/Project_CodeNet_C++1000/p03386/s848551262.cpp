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
    
    int A, B, K;
    io.read(A, B, K);
    set<int> st;
    for(int i = A; i <= min(A + K - 1, B); i++){
        st.insert(i);
    }
    for(int i = max(A, B - K + 1); i <= B; i++){
        st.insert(i);
    }
    for(auto i = st.begin(); i != st.end(); i++){
        cout << *i << '\n';
    }
    return 0;
}