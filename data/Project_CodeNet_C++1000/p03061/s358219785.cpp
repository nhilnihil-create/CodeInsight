#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll allg[1000000];

ll gcd(ll a, ll b){
    while(b != 0){
        ll tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

void allg_setter(vector<ll> &array,int n){
    allg[0] = array.at(0);
    //cout << allg[0] << " ";
    for(int i=1;i<n;i++){
        allg[i] = gcd(allg[i-1],array.at(i));
        //cout << allg[i] << " ";
    }
    //cout << endl;
}

ll maxg(vector<ll> &array,int n){
    if(n == 2){
        return max(gcd(array.at(0),array.at(1)),max(gcd(array.at(1),array.at(2)),gcd(array.at(0),array.at(2))));
    }
    ll g1 = gcd(maxg(array,n-1),array.at(n));
    //cout << g1 << " " << allg[n-1] << endl;
    return max(g1,allg[n-1]);
}


int main(){
    int n;
    cin >> n;
    vector<ll> array(n);
    for(int i=0;i<n;i++) cin >> array.at(i);
    
    allg_setter(array,n);
    if(n == 2){
        cout <<  max(array.at(0),array.at(1)) << endl;
    }else{
        cout << maxg(array,n-1) << endl;
    }
    
    /*for(int i=0;i<n;i++){
        cout << allg[i] << " ";
    }*/
}