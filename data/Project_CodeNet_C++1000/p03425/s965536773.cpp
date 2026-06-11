#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n; cin>>n;
    ll ans=0;
    vector<ll> lis(5,0);
    for (int i=0; i<n; i++){
        string s; cin >> s;
        char c=s[0];
        if(c=='M') lis[0]++;
        else if(c=='A') lis[1]++;
        else if(c=='R') lis[2]++;
        else if(c=='C') lis[3]++;
        else if(c=='H') lis[4]++;
    }
    for(int i=0; i<5; i++){
        for(int j=i+1; j<5; j++){
            for(int k=j+1; k<5; k++){
                ans += lis[i]*lis[j]*lis[k];
            }
        }
    }
    cout << ans << endl;
}