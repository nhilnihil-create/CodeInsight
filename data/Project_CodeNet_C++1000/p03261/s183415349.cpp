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
    int n;
    cin >> n;
    string ans = "Yes";
    vector<string> w(n);
    cin >> w.at(0);
    for(int i = 1; i < n; ++i){
        cin >> w.at(i);
        if(w.at(i - 1).back() != w.at(i).at(0)) ans = "No";
    }
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            if(w.at(i) == w.at(j)) ans = "No";
        }
    }
    cout << ans << endl;
    return 0;
}