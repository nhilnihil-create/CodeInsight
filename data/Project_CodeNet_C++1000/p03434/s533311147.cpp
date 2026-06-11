#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int alice=0,bob=0;
    sort(a.begin(),a.end());
    for(int i=1;i<=n;i++){
        if(i%2!=0){
            alice+=a[n-i];
        }else{
            bob+=a[n-i];
        }
    }
    cout <<alice-bob<< endl;

    return 0;
}