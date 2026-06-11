#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s[3];
    for(int i=0;i<3;i++) cin >> s[i];

    int count = 0;
    for(int i=0;i<n;i++){
        set<char> set1={};
        for(int j=0;j<3;j++){
            set1.insert(s[j][i]);
        }
        count += set1.size()-1;
    }
    cout << count << endl;
}
