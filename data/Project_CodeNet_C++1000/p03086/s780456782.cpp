#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<map>
#include<string>
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x) << endl
typedef long long ll;
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
 
using namespace std;

int main(){
    string S;   cin >> S;
    int l = S.length();
    int cnt, ans;
    cnt = 0;
    ans = 0;
    for(int i=0; i<l; i++){
        if(S[i] == 'A' || S[i] == 'T' || S[i] == 'G' || S[i] == 'C')    cnt++;
        else    cnt = 0;
        ans = max(ans,cnt);
    }
    print(ans);
}