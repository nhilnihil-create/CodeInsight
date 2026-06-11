#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n; cin>>n;
    double x[n];
    string u[n];
    double ans=0;
    for(int i=0;i<n;i++) cin>>x[i]>>u[i];
    for(int i=0;i<n;i++){
        if(u[i]=="JPY") ans+=x[i];
        else ans+=x[i]*380000;
    }
    cout<<ans<<endl;
    return 0;
}