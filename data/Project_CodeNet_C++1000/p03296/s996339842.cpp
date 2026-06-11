#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int cur;
    cin >> cur;
    int cnt=1;
    int ans=0;
    for(int n=1; n<N; n++) {
        int a;
        cin >> a;
        if(a==cur) {
            cnt++;
        } else {
            ans += cnt/2;
            cnt=1;
        }
        cur = a;
    }
    ans += cnt/2;
    cout << ans << endl;


    return 0;
    
}