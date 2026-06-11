#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<numeric>
#include<string>
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const ll MOD = 1000000007;
 
using namespace std;

int main(){
    string S;   cin >> S;
    int l = S.length();
    int ans = 999;
    for(int i=0; i<l-2; i++){
        ans = min(ans,abs(stoi(S.substr(i,3)) - 753));
    }
    cout << ans << endl;
}