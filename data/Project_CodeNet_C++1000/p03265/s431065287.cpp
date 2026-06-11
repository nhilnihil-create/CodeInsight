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
    
    int x1, y1, x2, y2;
    io.read(x1, y1, x2, y2);
    int a = x2 - x1;
    int b = y2 - y1;

    int x3 = a - b + x1;
    int y3 = a + b + y1;
    int x4 = -b + x1;
    int y4 = a + y1;

    cout << x3 << ' ' << y3 << ' ' << x4 << ' ' << y4;
    return 0;
}