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
    int N;
    cin >> N;
    int h[N];
    rep(i, N) cin >> h[i];
    int cnt = 0;
    while(1){
        bool is = true;
        rep(i, N){
            if(h[i] != 0) is = false;
        }
        if(is) break;

        int i = 0;
        while(i < N){
            if(h[i] <= 0) i++;
            else{
                cnt++;
                while(i < N && h[i] > 0){
                    h[i]--;
                    i++;
                }
            }
        }
    }
    cout << cnt << endl;
}