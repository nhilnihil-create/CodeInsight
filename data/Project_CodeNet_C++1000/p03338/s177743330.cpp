#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <set>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    int N;
    string S;
    cin >> N;
    cin >> S;
    int S_size = (int)S.size();

    int ans = 0;
    rep(i,S_size-1){
        string S1 = S.substr(0, i+1);
        string S2 = S.substr(i+1, S_size-i-1);
        int val = 0;

        set<char> set1(S1.begin(), S1.end());
        set<char> set2(S2.begin(), S2.end());
        for(char c: set1){
            for(char c2: set2){
                if(c == c2){
                    val += 1;
                }
            }
        }
        if( val > ans )ans=val;
        
    }

    cout << ans << endl;
    return 0;
}