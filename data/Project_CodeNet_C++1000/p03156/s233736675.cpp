#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll n,a,b;
    cin >> n >> a >> b;
    vector<int> p(n);
    ll i,j;
    ll iti=0,ni=0,san=0;
    for(i=0;i<n;i++){
        cin >> p.at(i);
        if(p.at(i)<=a)iti++;
        else if(p.at(i)<=b)ni++;
        else san++;
    }
    cout << min({iti,ni,san}) << endl;
    return 0;
}