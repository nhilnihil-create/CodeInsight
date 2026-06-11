#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a.at(i);
    }
    sort(a.begin(),a.end());

    vector<int> count(100001);
    int ans=0;
    for(int i=0; i<n; i++){
        if(a.at(i)>100000) ans++;
        else count.at(a.at(i))++;
    }
    
    for(int i=1; i<=100000; i++){
        if(count.at(i)<i) ans+=count.at(i);
        else ans+=count.at(i)-i;
    }

    cout << ans << endl;
}