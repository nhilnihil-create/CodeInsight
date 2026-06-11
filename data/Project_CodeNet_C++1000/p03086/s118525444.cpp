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
    string s;
    cin >> s;
    vector<int> a;
    for(int i = 0; i < s.size(); ++i){
        if(s.at(i) == 'A' || s.at(i) == 'C' || s.at(i) == 'G' || s.at(i) == 'T') a.push_back(i);
    }
    a.push_back(20);
    int cnt = 1, ans = 0;
    for(int i = 1; i < a.size(); ++i){
        if(a.at(i) - a.at(i - 1) == 1) cnt++;
        else{
            ans = max(ans, cnt);
            cnt = 1;
        }
    }
    cout << ans << endl;
    return 0;
}