#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main(){
    long long N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    vector<long long> raw;
    int flag;
    if(S[0] == '0') flag = 0;
    else flag = 1;
    raw.push_back(0);
    int cnt = 1;
    for(int i = 1; i < S.size(); i++){
        if(S[i] != S[i - 1]){
            raw.push_back(cnt);
            cnt = 1;
        }
        else cnt++;
    }
    raw.push_back(cnt);
    int l = 0, r;
    for(int i = 1; i < raw.size(); i++) raw[i] += raw[i - 1];
    if(flag == 0) r = 2 * K;
    else r = 2 * K + 1;
    long long ans = 0;
    int flag2 = 0;
    int flag3 = 0;
    while(r < raw.size()){
        ans = max(ans, raw[r] - raw[l]);
        if(flag3 == 0 && r + 2 >= raw.size()) r += 1;
        else r += 2;
        if(l ==0 && flag == 0) l++;
        else l += 2;
        flag2 = 1;
    }
    if(flag2 == 0){
        cout << S.size() << endl;
        return 0;
    }
    cout << ans << endl;
}