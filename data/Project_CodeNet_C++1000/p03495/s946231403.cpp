#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    int a[200010];
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }

    int res[200010] = {0};
    for(int i = 0; i < N; i++){
        res[a[i] - 1]++;
    
    }

    sort(res, res + N, greater<int>());

    int ans = 0;

    for(int i = 0; i < N; i++){
        if(res[i] > 0) ans++;
    }


    ans = ans - K;
    if(ans <= 0){
        cout << 0 << endl;
        return 0;
    }

    int ans2 = 0;
    for(int i = K; i < N; i++){
        ans2 += res[i];
    }

    cout << ans2 << endl;



}