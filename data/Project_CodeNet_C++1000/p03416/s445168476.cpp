#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
#include <math.h>
#include <map>
#include <stack>
using namespace std;
static const int INF = 1e9+7;
// 型定義
typedef long long ll;
typedef pair<ll, ll> P;

#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, a, b) for (int i =a; i < b; i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define PI 3.14159265359

int kaibun(string num){
    if(num.size() == 1){
        return 0;
    }else{
        rep(i, (num.size() / 2)){
            if(num[i] != num[num.size() - i - 1]){
                return 0;
            }
        }
        return 1;
    }
}


int main(){
    int a, b; cin >> a >> b;
    int result = 0;
    repr(i, a, b+1){
        string tmp = to_string(i);
        result += kaibun(tmp);
    }
    cout << result << endl;
    return 0;
}
