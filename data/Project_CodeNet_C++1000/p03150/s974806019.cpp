#include<bits/stdc++.h>
using namespace std;

int main(){
    string rev_s; cin >> rev_s;
    string s = rev_s;
    reverse(rev_s.begin(), rev_s.end());
    string key = "keyence";
    string rev_key = "ecneyek";
    int cnt=0, rev_cnt=0;
    int n = s.length();
  
    for(int i=0; i<n; i++){
        if(s[i] == key[cnt]){
            cnt++;
            if(cnt == 7){
                cout << "YES" << endl;
                return 0;
            }
        }else{
            break;
        }
    }
    for(int i=0; i<n; i++){
        if(rev_s[i] == rev_key[rev_cnt]){
            rev_cnt++;
            if(rev_cnt == 7){
                cout << "YES" << endl;
                return 0;
            }
        }else{
            break;
        }
    }
    if(cnt + rev_cnt >= 7){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}