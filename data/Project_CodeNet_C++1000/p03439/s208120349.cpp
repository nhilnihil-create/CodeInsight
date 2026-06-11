#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const int MOD = 1e9 + 7;

signed main(){
    int n;
    cin >> n;
    string s;
    string even;
    cout << 0 << endl;
    cin >> s;
    if(s == "Male"){
        even = s;
    }else if(s == "Female"){
        even = s;
    }else{
        return 0;
    }
    int left = -1, right = n;
    while(abs(right - left) > 1){
        int mid = (right + left) / 2;
        cout << mid << endl;
        cin >> s;
        if(s == "Vacant"){
            return 0;
        }else if((mid % 2 == 0 && s == even) || (mid % 2 == 1 && s != even)){
            left = mid;
        }else{
            right = mid;
        }
    }
    return 0;
}