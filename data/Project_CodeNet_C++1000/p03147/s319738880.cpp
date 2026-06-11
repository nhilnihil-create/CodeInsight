#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
using namespace std;
int main(void){
    int N; cin >> N;
    vector<int> h(N);
    vector<int> f(N,0);
    int i = 0;
    int ans = 0;
    while(N > i){
        cin >> h[i];
        i++;
    }
    while(true){
        i = 0;
        int flag = false;
        int first = true;
        while(i < N) {
            if (f[i] == h[i] && flag) {
                flag = 0;
            } else if (flag == 0 && f[i] < h[i]) {
                flag = 1;
                f[i]++;
                ans++;
            } else if (h[i] > f[i]) {
                f[i]++;
            }
            i++;
        }
        int j = 0;
        int bflag = 1;
        while (j < N) {
            if (h[j] != f[j]) bflag = 0;
            j++;
        }
        if (bflag)  {
            cout << ans << endl;
            return 0;
        }
    }
}