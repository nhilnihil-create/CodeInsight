#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    vector <int> a(s.length());
    vector <int> diff9(s.length());
    vector <int> diff9Sum(s.length(),0);
    for(int i = 0; i < s.length(); i++){
        a[i] = (int)((int)s[i] - (int)'0');
        diff9[i] = 9-a[i];
        if(i==0){
            diff9Sum[i] = diff9[i];
        }else{
            diff9Sum[i] = diff9[i] + diff9Sum[i];
        }
    }
    long ans = 0;
    for(int i = 1; i < s.length(); i++){
        if(diff9[i]==0){
            continue;
        }else{
            a[i-1]--;
            for(int j = i; j < s.length(); j++){
                a[j] = 9;
            }
            break;
        }
    }
    for(int i = 0; i < s.length(); i++){
        //cout << a[i];
        ans+=a[i];
    }
    //cout << endl;
    cout << ans << endl;


}