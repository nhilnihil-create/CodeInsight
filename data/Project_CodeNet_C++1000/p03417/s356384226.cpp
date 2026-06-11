#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,m;
    cin >> n >> m;
    if(n>=2 && m>=2){
        cout << (n-2)*(m-2) << endl;
    }
    else if(n==1 && m!= 1){
        cout << (m-2) << endl;
    }
    else if(n!=1 && m ==1){
        cout << (n-2) << endl;
    }
    else{
        cout << 1 << endl;
    }
}