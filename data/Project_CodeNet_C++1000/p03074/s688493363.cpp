#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
using ll = long long;
int main(void){
    ll n,k;
    cin >> n >> k;
    string str;
    cin >> str;

    ll cnt = 0;
    ll i = 0;
    if(str[0]=='1') cnt--;
    while(i<n && cnt<k){
        if(str[i]=='1'&&str[i+1]=='0') cnt++;
        i++;
    }
    ll ans = i;
    ll back_i=0;
    str = str + "0";
    while(i<n){
        while(!(str[i]=='1'&&str[i+1]=='0')&&i<n-1) i++;
        while(!(str[back_i]=='0'&&str[back_i+1]=='1')&&back_i<n) back_i++;
        back_i++;
        i++;
        //cout << "back_i : " << back_i << "  i : " << i << endl;
        ans = max(ans, i-back_i);

    }
    cout << ans << endl;
    return 0;
} 