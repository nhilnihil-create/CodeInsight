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
    ll N;
    cin >> N;
    int head;
    int keta = 1;
    ll num = N;
    bool is_nine = true;
    while(1){
        if(num / 10 == 0){
            head = num;
            break;
        }else{
            if(num % 10 != 9) is_nine = false;
            num /= 10;
            keta++;
        }
    }
    int ans;
    if(is_nine){
        ans = head + 9 * (keta - 1);
    }else{
        ans = head + 9 * (keta - 1) - 1;
    }
    cout << ans << endl;
    return 0;
}