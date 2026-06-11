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
    vector<string> W(N);
    for(int i = 0; i < N; i++){
        io.read(W[i]);
    }
    set<string> st;
    st.insert(W[0]);
    string ans = "Yes";
    for(int i = 1; i < N; i++){
        if(W[i - 1].back() != W[i].front() || st.find(W[i]) != st.end()){
            ans = "No";
            break;
        }
        st.insert(W[i]);
    }
    cout << ans;
    return 0;
}