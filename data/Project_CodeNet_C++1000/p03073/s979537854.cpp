#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;
#define reverse(s) reverse(s.begin(),s.end())

int main(){
    string s,a(""),b("");
    cin >> s;

    rep(i,s.size()){
        if(i%2==0){
            a += '0';
            b += '1';
        }else{
            a += '1';
            b += "0";
        }
    }

    int sum_a(0),sum_b(0);
    rep(i,s.size()){
        if(a[i]==s[i]){
            sum_a++;
        }else{
            sum_b++;
        }
    }

    cout << s.size()-max(sum_a,sum_b) << endl;

    return 0;
}