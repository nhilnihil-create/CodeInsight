#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;



int main(){
    ll n;
    cin >> n;
    cout << 0 << endl;
    vector<string> s(n);
    string s0;
    cin >> s0;
    s[0]=s0;
    if(s0=="Vacant"){
        cout << 0 << endl;
        return 0;
    }
    cout << n-1 << endl;
    string sn1;
    cin >> sn1;
    s[n-1]=sn1;
    if(sn1=="Vacant"){
        cout << n-1 << endl;
        return 0;
    }
    ll l=0;
    ll r=n-1;
    while(1){
        ll mid=(l+r)/2;
        cout << mid << endl;
        string smid;
        cin >> smid;
        s[mid]=smid;
        if(smid=="Vacant"){
            cout << mid << endl;
            return 0;
        }
        if((mid-l)%2==0&&s[mid]!=s[l]) r=mid;
        else if((mid-l)%2==1&&s[mid]==s[l]) r=mid;
        else if((r-mid)%2==0&&s[mid]!=s[r]) l=mid;
        else if((r-mid)%2==1&&s[mid]==s[r]) l=mid;
    }
}  
