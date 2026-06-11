#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

bool f[1000010];

int main(){
    int s;
    cin >> s;
    rep(i,1000010) f[i] = false;
    f[s] = true;
    
    int tmp = s;
    int cnt = 1;
    if(tmp % 2 == 0){
        tmp = tmp/2;
    }else{
        tmp = 3*tmp+1;
    }

    while(f[tmp] == false){
        f[tmp] = true;
        if(tmp % 2 == 0){
            tmp = tmp/2;
        }else{
            tmp = 3*tmp+1;
        }
        cnt++;
    }
    cnt++;
    
    cout << cnt << endl;
    return 0;
}