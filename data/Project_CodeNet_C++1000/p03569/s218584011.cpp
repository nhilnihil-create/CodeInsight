#include<bits/stdc++.h>
using namespace std;

int main(){
    string s,rev,no_x,pali;
    int i,j,k,left_x = 0,right_x = 0,ans = 0;
    cin >> s;
    rev = s;
    for(int i = 0;i < s.size();i++){
        if(s[i] != 'x'){
            no_x.push_back(s[i]);
            pali.push_back(s[i]);
        }
    }
    reverse(pali.begin(),pali.end());

    if(no_x != pali){
        cout << -1 << endl;
        return 0;
    }
    reverse(rev.begin(),rev.end());

    for(i = 0,j = 0,k = 0;i < s.size() && j < rev.size();i++,j++){
        if(s[i] == 'x' && rev[j] != 'x')while(s[i] == 'x')i++,ans++;
        else if(s[i] != 'x' && rev[j] == 'x')while(rev[j] == 'x')j++,ans++;
        if(s[i] == 'x' && rev[j] == 'x')continue;
        k++;
        if(k > (no_x.size() / 2))break;
    }
    cout << ans << endl;
}
