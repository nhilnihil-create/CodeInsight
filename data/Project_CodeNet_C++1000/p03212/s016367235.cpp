#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

long long N;
int digit;  // Nの桁数
int cnt = 0;

int ref(int depth, long long x, bool a, bool b, bool c){ // a, b, c は7, 5, 3がそれぞれ1つでもあるかを表す。  
    if(depth == digit){
        if(x<=N && a && b && c){
            cnt += 1;
            //cout << x << endl;  // テスト用
            return 0;
        }
        return 0;
    }
        
    ref(digit, x, a, b, c);
    ref(depth+1, x*10+7, true, b, c);
    ref(depth+1, x*10+5, a, true, c);
    ref(depth+1, x*10+3, a, b, true);
    
    return 0;
}

int main(){
    cin >> N;
    digit = log10(N)+1;
    ref(0, 0, false, false, false);
    cout << cnt << endl;
}