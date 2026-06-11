#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    ll ans =0;
    ll aend =0;
    ll bstart =0;
    ll aendbstart =0;
    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        if(s[0] == 'B'){
            bstart++;
        }
        if(s[s.size()-1] == 'A'){
            aend++;
        }
        if(s[0] == 'B' && s[s.size()-1] == 'A'){
            aendbstart++;
        }
        for(int j=0;j<s.size()-1;j++){
            if(s[j] == 'A' &&s[j+1] =='B'){
                ans++;
            }
        }
    }
    if(aendbstart ==0){
        cout << ans + min(bstart,aend) << endl;
        return 0;
    }
    
    bstart -= aendbstart;
    aend -= aendbstart;
    ans += (aendbstart-1);
    if(aend >0){
        ans++;
        aend--;
    }
    if(bstart >0){
        ans++;
        bstart--;
    }
    cout << ans + min(bstart,aend)<< endl;
    return 0;
}
