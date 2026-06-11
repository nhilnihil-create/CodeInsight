#include <bits/stdc++.h>
using namespace std;
int abs(int x){
    if(x<0) return -x;
    else return x;
}

int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    int alice=0,bob=0;
    for(int i=0;i<n;i++) cin>>a.at(i);
    sort(a.begin(),a.end());
    for(int i=0;i<n;i+=2){
        alice+=a.at(i);
    }
    for(int i=1;i<n;i+=2){
        bob+=a.at(i);
    }
    cout<<abs(alice-bob)<<endl;
}