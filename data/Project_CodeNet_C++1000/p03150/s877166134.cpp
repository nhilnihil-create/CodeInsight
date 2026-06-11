#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    string S;
    cin >> S;
    string key = "keyence";
    int N = (int)S.size();
    bool is = false;
    if(S == key){ //取り除く文字列が空の時に満たされる
        cout << "YES" << endl;
        return 0;
    }
    for(int i = 0; i < N; i++){
        for(int j = N-i; j >= 1; j--){
            string af = S;
            af.erase(i, j);
            if(af == key) is = true;
        }
    }
    if(is) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}