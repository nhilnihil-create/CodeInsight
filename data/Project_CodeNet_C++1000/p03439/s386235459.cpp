#include <bits/stdc++.h>
using namespace std;

bool ok(string s){
    if(s=="Vacant") return true;
    else return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<string> s(n);
    cout<<0<<endl;
    cin>>s[0];
    if(ok(s[0])) return 0;  
    cout<<n-1<<endl;
    cin>>s[n-1];
    if(ok(s[n-1])) return 0;
    int lb =0,ub=n-1;
    while(ub-lb>1){
        int mid = (ub+lb)/2;
        cout<<mid<<endl;
        cin>>s[mid];
        if(ok(s[mid])) return 0;
        if((mid-lb)%2)s[mid]!=s[lb]? lb = mid:ub = mid; 
        else s[mid]==s[lb]?lb = mid:ub=mid;
    }
    cout << ub << endl;
    cin >> s[ub];
    if(ok(s[ub])) return 0;
    cout << lb << endl;
    cin >> s[lb];
    return 0;
}