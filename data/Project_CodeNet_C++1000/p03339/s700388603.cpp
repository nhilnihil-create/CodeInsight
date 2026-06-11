#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    string str;
    cin >> str;
    vector<int> Enum(N, 0);
    vector<int> Wnum(N, 0);
    for(int n=0; n<N; n++) {
        if(n>0) {
            Wnum[n] += Wnum[n-1];
            Enum[N-1-n] += Enum[N-n];
            
            if(str[n-1]=='W') Wnum[n]++;
            if(str[N-n]=='E') Enum[N-1-n]++;
        }
    }
    
    int ans=N;
    for(int n=0; n<N; n++) {
        ans = min(ans, Wnum[n]+Enum[n]);
    }
    cout << ans << endl;

    return 0;
    
}