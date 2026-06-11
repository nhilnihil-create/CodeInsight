#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    string march = "MARCH";
    string s;
    vector<long long> count(5);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> s;
        for(int j = 0; j < 5; j++){
            if(march[j] == s[0]){
                count[j]++;
                break;
            }
        }
    }

    long long ans = 0;
    for(int i = 0; i < 5; i++){
        for(int j = i+1; j < 5; j++){
            for(int k = j+1; k < 5; k++){
                ans += count[i] * count[j] * count[k];
            }
        }
    }

    cout << ans << endl;

    return 0;
}