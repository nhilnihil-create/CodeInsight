#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    int N;
    string S;
    cin >> N >> S;
    int ans = 0;
    for(int i = 0; i < N - 1; i++){
        int cnt = 0;
        vector<int> c1(26), c2(26);
        for(int j = 0; j < N; j++){
            if(j <= i){
                c1[S[j] - 'a']++;
            }
            else c2[S[j] - 'a']++;
        }
        for(int j = 0; j < 26; j++){
            if(c1[j] > 0 && c2[j] > 0) cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}