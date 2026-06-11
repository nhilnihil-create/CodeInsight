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
    ll A, B, C, K;
    cin >> A >> B >> C >> K;
    ll ans;
    if(K % 2 == 0){
        ans = A - B;
    }else{
        ans = B - A;
    }

    if(ans > pow(10, 18)){
        cout << "Unfair" << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}