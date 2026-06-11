#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, t, ci, ti, r=1001;

    cin>>n>>t;

    while(n--){
        cin>>ci>>ti;
        if(ti<=t && ci<r){
            r=ci;
        }
    }

    r<1001?cout<<r:cout<<"TLE";

    return 0;
}