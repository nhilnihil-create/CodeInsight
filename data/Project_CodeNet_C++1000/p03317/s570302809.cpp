#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<utility>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;

using ll = long long;

void read();
template<typename First, typename... Rest> void read(First& first, Rest&... rest);
void write();
template<typename First, typename... Rest> void write(First first, Rest... rest);
template<typename T> void write_vec(vector<T>& v, char divider);

int main(){
    int N, K;
    read(N, K);
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        read(A[i]);
    }
    N -= K;
    int ans = 1;
    if(N > 0) {
        ans += N / (K - 1);
        if(N % (K - 1)) ans++;
    }
    write(ans);
    return 0;
}

//配列以外の入力を受け取る
void read(){

}
template<typename First, typename... Rest>
void read(First& first, Rest&... rest){
    cin >> first;
    read(rest...);
}
//
//配列以外を出力する
void write(){

}
template<typename First, typename... Rest>
void write(First first, Rest... rest){
    cout << first << " ";
    write(rest...);
}
//
//配列を区切って出力する
template<typename T>
void write_vec(vector<T>& v, char divider){
    for(size_t i = 0; i < v.size(); i++){
        cout << v[i] << divider;
    }
}
//