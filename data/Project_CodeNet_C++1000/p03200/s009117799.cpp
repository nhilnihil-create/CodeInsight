#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    long long int n = s.length();
    long long int ans  = 0;
    long long int cnt = 0;
    for (long long int i=0; i<n; i++){
        if (s[i] == 'W'){
            ans += i-cnt;
            cnt++;
        }
    }
    cout<<ans<<endl;
}