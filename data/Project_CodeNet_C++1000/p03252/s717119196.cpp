#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> P;

int main(){
    string s,t;
    cin >> s;
    cin >> t;
    int alphabet1[26];
    int alphabet2[26];
    for(int i = 0; i < 26; i++){
        alphabet1[i]  = -1;
        alphabet2[i] = -1;

    }
    bool ok = true;
    for(int i = 0; i < s.length();i++){
        int index1,temp1;
        index1 = s[i] - 'a';
        temp1 = t[i] - 'a';
        if(alphabet2[temp1] == -1){
            alphabet2[temp1] = index1;
        }
        if(alphabet1[index1] == -1){
            alphabet1[index1] = temp1;
        }
        if(alphabet2[temp1] != index1 || alphabet1[index1] != temp1){
            ok = false;
            break;
        }
    }
    /*for(int i = 0; i < s.length();i++){
        cout << "unchi" << i+1 << alphabet[i] << endl;
    }*/
    if(ok){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}