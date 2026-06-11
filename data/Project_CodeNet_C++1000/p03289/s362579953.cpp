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
    string s, ans = "AC";
    cin >> s;
    int cnt = 0;
    if(s.at(0) != 'A'){
        ans = "WA";
    }
    else{
        for(int i = 1; i < s.size(); ++i){
            if(isupper(s.at(i))){
                if(i == 1 || i == s.size() - 1 || s.at(i) != 'C'){
                    ans = "WA";
                }
                cnt++;
            } 
        }
        if(cnt != 1) ans = "WA";
    }
    cout << ans << endl;
    return 0;
}