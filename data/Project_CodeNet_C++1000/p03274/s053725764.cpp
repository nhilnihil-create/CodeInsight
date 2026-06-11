#include <iostream>
#include <vector>
using namespace std;
int func1(int a,int b){
    return min(abs(a) + abs(a-b), abs(b) + abs(a-b));
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<int> x(n); for(int i = 0; i < n; ++i){
        cin >> x[i];
    }
    long long ans = 1L<<60;
    for(int i = 0; i+k-1 < n; ++i){
        ans = min(ans, (long long)func1(x[i], x[i+k-1]));
    }
    cout << ans << endl;
    return 0;
}
//Saw the solution video