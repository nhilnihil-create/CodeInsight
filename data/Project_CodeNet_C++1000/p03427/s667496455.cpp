#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    string s;
    cin >> s;
    int ans1 = 0;
    for(int i=0;i<s.size();i++){
        ans1 += s[i] - '0';
    }

    int ans2 = s[0]-'1' +(s.size()-1)*9;
    cout << max(ans1,ans2) << endl;
}
