#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstdlib>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    string s;
    cin >> s;
    int a[3] = {0, 0, 0};
    rep(i, 3){
        int idx = s[i] - 'a';
        if (a[idx] != 0){
            cout << "No" << endl;
            return 0;
        }
        a[idx]++;
    }
cout << "Yes" << endl;
}