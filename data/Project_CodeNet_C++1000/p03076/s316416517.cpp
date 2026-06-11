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

    int A, B, C, D, E;
    io.read(A, B, C, D, E);
    int ans = 0;
    ans += A + (10 - A % 10) % 10;
    ans += B + (10 - B % 10) % 10;
    ans += C + (10 - C % 10) % 10;
    ans += D + (10 - D % 10) % 10;
    ans += E + (10 - E % 10) % 10;

    int m = 0;
    m = max(m, (10 - A % 10) % 10);
    m = max(m, (10 - B % 10) % 10);
    m = max(m, (10 - C % 10) % 10);
    m = max(m, (10 - D % 10) % 10);
    m = max(m, (10 - E % 10) % 10);
    ans -= m;
    io.write(ans);
    return 0;
}