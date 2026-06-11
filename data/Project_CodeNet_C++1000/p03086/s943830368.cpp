#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
const long long inf = 1000000001; // const 書き換え禁止
const double PI = 3.14159265358979323846; //M_PI はライブラリ

int main(void){
    string s;
    cin >> s;
    int ans = 0;
    for(int i=0;i<s.size();i++){
        int count = 0;
        for(int j=i;j<s.size();j++){
            if(s[j] == 'A' || s[j] == 'C' || s[j] == 'G' || s[j] == 'T'){
                count++;
            }else{
                break;
            }
        }
        if(count > ans){
            ans = count;
        }
    }
    cout << ans << endl;
}