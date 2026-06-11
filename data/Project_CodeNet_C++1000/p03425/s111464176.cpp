#include <iostream>
#include <string>
using namespace std;
int num[5];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    char c[5] = {'M','A','R','C','H'};
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        string s; cin >> s;
        for(int j = 0; j < 5; ++j){
            if(s[0] == c[j]) num[j]++;
        }
    }
    long long ans = 0;
    for(int i = 0; i < 1<<5; i++){
        if(__builtin_popcount(i) != 3) continue;
        long long tmp = 1;
        for(int j = 0; j < 5; ++j){
            if((i>>j)&1) tmp *= num[j];
        }
        ans += tmp;
    }
    cout << ans << endl;
    return 0;
}