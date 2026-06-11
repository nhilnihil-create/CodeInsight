#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<string>
#define all(x) (x).begin(),(x).end()
typedef long long ll;

using namespace std;

int main()
{
    string s;   cin >> s;
    int l = s.length();
    s += "ZZZZZZZZ";

    ll abc, a, bc, ans;
    abc = 0;
    a = 0;
    bc = 0;
    ans = 0;
    int i=0;
    while(i < l){
        if(s.substr(i,3) == "ABC"){
            abc++;
            ans += abc + a;
            i += 3;
        }else if(s.substr(i,1) == "A"){
            a++;
            i++;
        }else if(abc > 0 && s.substr(i,2) == "BC"){
            ans += abc + a;
            i += 2;
        }else{
            abc = 0;
            a = 0;
            bc = 0;
            i++;
        }
    }
    cout << ans << endl;
    return 0;
}