#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int MOD = 1000000007;
typedef long long ll;

template<typename T> void print(const T & v);


int main() {
    int N;
    cin >> N;
    if(N == 1){
        cout << "Hello World" << endl;
        return 0;
    }else{
        int a, b;
        cin >> a >> b;
        cout << a + b << endl;
        return 0;
    }
}


// Use For Debug
template <typename T>
void print(T const & v){
    for(int i = 0; i < v.size(); i++){
        if(i) cout << " ";
        cout << v[i];
    }
    cout << endl;
}
