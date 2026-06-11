// #include <iostream>
#include<bits/stdc++.h>
#include<vector>

using namespace std;

int main() {
    long int n;
    int k;
    cin>>n>>k;
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
        while(j<n && j<=i+k){
            b[i] = min(abs(a[i]-a[j]) + b[j] , b[i]);
            j++;
        }
        
    }
    cout<<b[0];

    
}