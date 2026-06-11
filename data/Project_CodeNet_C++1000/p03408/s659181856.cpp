#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    string s[N];
    for(int i = 0; i < N; i++){
        cin >> s[i];
    }
    int M;
    cin >> M;
    string t[M];
    for(int i = 0; i < M; i++){
        cin >> t[i];
    }

    int ans = 0;
    for(int i = 0; i < N; i++){
        int max = 0;
        for(int j = 0; j < M; j++){
            if(s[i]==t[j]) max--;
        }
        for(int j = 0; j < N; j++){
            if(s[i]==s[j]) max++;
        }

        if(ans < max) ans = max;
    }

    if(ans >= 0) cout << ans << endl;
    else cout << 0 << endl;
}