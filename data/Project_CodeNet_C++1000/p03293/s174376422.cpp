#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstddef>
#include<queue>
#include<math.h>
#include<iomanip>
using namespace std;

int main()
{
    string s, t, ans = "No";
    cin >> s >> t;
    string trot = t;
    if(t == s) ans = "Yes";
    else{
        for(int i = 0; i < t.size(); ++i){
            char move = trot.at(trot.size() - 1);
            trot.pop_back();
            trot =  move + trot;
            if(trot == s){
                ans = "Yes";
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}