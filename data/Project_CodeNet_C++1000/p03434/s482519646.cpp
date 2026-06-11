#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define ll long long

int main(){
    int n;
    int alice=0,bob=0;
    cin >> n;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
    }
    sort(a.begin(),a.end(),greater<int>());
    for(int i=0;i<n;i+=2){
        alice+=a[i];
    }
    for(int j=1;j<n;j+=2){
        bob+=a[j];
    }
    cout << alice-bob << endl;
}