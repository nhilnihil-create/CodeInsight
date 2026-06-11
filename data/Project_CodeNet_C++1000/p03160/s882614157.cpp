// #include <iostream>
#include<bits/stdc++.h>
#include<vector>

using namespace std;

int main() {
    long int n;
    cin>>n;
    int b[n];
    vector<int>a;
    for(auto i = 0 ; i< n ; i++){
        int t;
        cin>>t;
        a.push_back(t);
    }
    b[n-1] = 0;
    for(auto i = n-2 ; i >=0 ; i--){
        int j = i+2;
        b[i] = abs(a[i]-a[i+1]) + b[i+1];
        if(j<n){
            b[i] = min(abs(a[i]-a[j]) + b[j] , b[i]);
        }
        
    }
    cout<<b[0];

    
}