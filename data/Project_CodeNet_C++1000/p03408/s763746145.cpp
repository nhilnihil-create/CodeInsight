#include <iostream>
#include <map>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;
int main(void){
    
    
    map<string, int> m;
    
    int N;
    cin >> N;    
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        m[s]++;
    }
    
    int M;
    cin >> M;
    for(int i = 0; i < M; i++){
        string s;
        cin >> s;
        m[s]--;
    }
    
    int ans = 0;
    for(auto A : m){
        auto value = A.second;
        ans = max(ans, value);
    }
    cout << ans << endl;
    
}
