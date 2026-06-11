#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
int main(){
    long long N;
    cin >> N;
    vector<long long> cnt(5);
    for(int i = 0; i < N; i++){
        string S;
        cin >> S;
        if(S[0] == 'M') cnt[0]++;
        else if(S[0] == 'A') cnt[1]++;
        else if(S[0] == 'R') cnt[2]++;
        else if(S[0] == 'C') cnt[3]++;
        else if(S[0] == 'H') cnt[4]++;
    }
    long long ans = 0;
    for(int bit = 0; bit < (1 << 5); bit++){
        long long sum = 1;
        int cn = 0;
        for(int j = 0; j < 5; j++){
            if(bit & (1 << j)) {
                sum *= cnt[j];
                cn++;
            }
        }
        if(cn == 3) ans += sum;
    }
    cout << ans << endl;
}