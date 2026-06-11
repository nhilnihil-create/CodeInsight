#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    int N;
    string S;
    cin >> N >> S;
    vector<int> cntl(N + 1);
    for(int i = 0; i < N; i++){
        if(S[i] == 'E') cntl[i + 1] = cntl[i] + 1;
        else cntl[i + 1] = cntl[i];
    }
    int ans = 1e9;
    for(int i = 0; i < N; i++){
        int t = i - cntl[i] +  (cntl[N] - cntl[i + 1]);
        ans = min(ans, t);
    }
    cout << ans << endl;
}