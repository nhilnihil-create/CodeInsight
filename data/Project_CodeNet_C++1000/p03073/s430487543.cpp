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

    string S;
    io.read(S);
    int a = 1;
    int b = 0;
    int sum1 = 0;
    int sum2 = 0;
    for(int i = 0; i < S.size(); i++){
        if(S[i] - '0' != a) {
            sum1++;
        }
        else {
            sum2++;
        }
        swap(a, b);
    }
    io.write(min(sum1, sum2));
    return 0;
}