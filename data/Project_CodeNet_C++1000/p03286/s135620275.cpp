#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    int N;
    cin >> N;

    if(N==0){
        cout << 0 << endl;
        return 0;
    }

    int s = N;
    string ans = "";
    while(s != 0){
        if(s % (-2) == 0){
            ans += "0";
            s /= (-2);
        }else{
            ans += "1";
            s--;
            s /= (-2);
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;

    return 0;
}
