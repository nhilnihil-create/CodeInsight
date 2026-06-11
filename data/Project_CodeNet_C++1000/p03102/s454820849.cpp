#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
using namespace std;
int main(void){
    int N,M,C; cin >> N >> M >> C;
    vector<int> b(M);
    vector< vector<int> > a(N, vector<int>(M));
    int i = 0;
    int ans = 0;
    int j = 0;
    while(j < M) {
        cin >> b[j];
        j++;
    }
    while (i < N) {
        int tmp = 0;
        int j = 0;
        while(j < M) {
            int tmp2 = 0;
            cin >> tmp2;
            tmp += tmp2 * b[j];
            j++;
        }
        if (tmp > -C) ans++;
        i++;
    }
    cout << ans << endl;
}