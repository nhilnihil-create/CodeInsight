#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    long ans = 0;
    long cur = 0;
    int t = -1;
    int a[N];
    for(int i=0; i<N; i++){
        cin >> a[i];
        while((cur + a[i]) != (cur ^ a[i])){
            t++;
            cur -= a[t];
        }
        ans += i - t;
        cur += a[i];
    }
    cout << ans << endl;
    return 0;
}