#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(void){
    int N;
    cin >> N;
    long long ans = 0;
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        ans += a;
    }
    ans -= N;
    cout << ans << endl;
}
