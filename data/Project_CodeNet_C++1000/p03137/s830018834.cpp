#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
#include <algorithm>
using namespace std;
int main(void){
    int N, M; cin >> N >> M;
    int i = 0;
    vector<int> x(M);
    vector<int> d(M-1);
    while(M > i){
        cin >> x[i];
        i++;
    }
    sort(x.begin(), x.end());
    i = 1;
    while (M > i) {
        d[i-1] = abs(x[i] - x[i-1]);
        i++;
    }
    sort(d.begin(), d.end());
    i = 0;
    int ans = 0;
    for (int count = 0; count < M - N; count++) {
        ans += d[count];
    }
    cout << ans << endl;
}
