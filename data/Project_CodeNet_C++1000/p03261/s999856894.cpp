#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    IOS;
    int n;
    cin >> n;
    vector<string> str;
    vector<string> sn;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        str.push_back(s);
        sn.push_back(s);
    }
    sort(str.begin(),str.end());
    for(int i=0; i<str.size(); i++){
        if(str[i]==str[i-1]){
            cout << "No" <<endl;
            return 0;
        }
    }
    bool ans = false;
    for(int i=1; i<sn.size(); i++){
        int ind = sn[i-1].size()-1;
        char first = sn[i][0];
        char last = sn[i-1][ind];
        if(first!=last){
            cout << "No" <<endl;
            return 0;
        }else{
            ans = true;
        }
        
    }
    if(ans == true){
        cout << "Yes" <<endl;
    }
}