#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    int k;
    cin >> s;
    cin >> k;

    vector<string> data;

    for(int i = 0; i < s.size(); ++i){
        for(int j = 1; j <= k; ++j){
            if(i + j - 1 < s.size()){
                data.push_back(s.substr(i,j));
            }
        }
    }

    sort(data.begin(), data.end());

    unique(data.begin(),data.end());

    cout << data[k - 1] << endl;

    return 0;
}