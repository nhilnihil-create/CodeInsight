#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    string S;
    cin >> S;

    if (S.size()==1){
        cout << "YES" << endl;
        return 0;
    }

    vector<int> cnt(3,0);
    for(int i=0; i<S.size(); i++){
        int n = S[i]-'a';
        cnt[n]++;
    }
    int max_ = *max_element(cnt.begin(),cnt.end());
    int min_ = *min_element(cnt.begin(),cnt.end());
    string ans = "NO";
    if (S.size()==1 && max_!=2){
        ans = "YES";
    }else if(max_-min_<2){
        ans="YES";
    }
    cout << ans << endl;
}