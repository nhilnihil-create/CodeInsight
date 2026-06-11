#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    string S;
    cin >> S;
    int N = (int)S.size();
    vector<bool> used(30, false);
    if(N != 26){
        char w;
        rep(i, N) used[S[i] - 'a'] = true;
        rep(i, 26){
            if(!used[i]){
                w = char(i + 'a');
                break;
            }
        }
        S.push_back(w);
        cout << S << endl;
        return 0;
    }else{
        string T;
        T = S;
        bool exist = next_permutation(S.begin(), S.end());
        if(!exist){
            cout << -1 << endl;
            return 0;
        }
        string ans;
        rep(i, N){
            ans.push_back(S[i]);
            if(S[i] > T[i]){
                break;
            }
        }
        cout << ans << endl;
        return 0;
    }
}