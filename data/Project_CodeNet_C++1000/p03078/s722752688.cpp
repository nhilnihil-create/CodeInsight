#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int x,y,z,k;
    cin >> x >> y >> z >> k;

    vector<ll> a(x),b(y),c(z);
    for(int i=0;i<x;i++) cin >> a[i];
    for(int i=0;i<y;i++) cin >> b[i];
    for(int i=0;i<z;i++) cin >> c[i];

    vector<ll> ab;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            ab.push_back(a[i]+b[j]);
        }
    }
    sort(ab.begin(),ab.end());
    reverse(ab.begin(),ab.end());

    vector<ll> abc;
    sort(c.begin(),c.end());
    for(int i=0;i<min(x*y,k);i++){
        for(int j=0;j<z;j++){
            abc.push_back(ab[i]+c[j]);
        }
    }
    sort(abc.begin(),abc.end());
    reverse(abc.begin(),abc.end());

    for(int i=0;i<k;i++) cout << abc[i] << endl;
}