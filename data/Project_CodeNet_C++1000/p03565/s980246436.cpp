#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<map>
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x) << endl
typedef long long ll;
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
 
using namespace std;
using Graph = vector<vector<int>>;

int main(){
    string S, T, S1, tmp, ans;    cin >> S >> T;
    int s = S.length(), t = T.length();
    ans = "";
    int l = 0;
    for(int i=0; i<s; i++)  ans += 'z';
    for(int i=0; i<s-t+1; i++){
        tmp = S;
        S1 = S;
        for(int j=0; j<s; j++) if(S1[j] == '?') S1[j] = 'a';
        if(S[i] == '?') tmp[i] = T[0];
        if(tmp[i] == T[0]){
            for(int j=0; j<t; j++){
                if(tmp[i+j] != T[j] && tmp[i+j] != '?')   break;
                else if(j == t-1){
                    for(int k=0; k<t; k++)  S1[i+k] = T[k];
                    if(S1 < ans)    ans = S1;
                    l = 1;
                }
            }
        }
    }
    if(l == 0)   print("UNRESTORABLE");
    else    print(ans);
}