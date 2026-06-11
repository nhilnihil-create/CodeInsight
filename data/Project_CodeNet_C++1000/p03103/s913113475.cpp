#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    ll n,m;
    cin >> n >> m;
    vector<pair<ll,ll>> array(n);
    for(int i=0;i<n;i++){
        cin >> array.at(i).first >> array.at(i).second;
    }
    sort(array.begin(),array.end());
    
    ll money = 0;
    
    for(int i=0;i<n;i++){
        if(m <= array.at(i).second){
            money += array.at(i).first * m;
            break;
        }else{
            money += array.at(i).first * array.at(i).second;
            m -= array.at(i).second;
        }
    }
    cout << money << endl;
}