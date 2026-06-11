#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
//もっともっと簡単に
int main(){
    int n; cin>>n;
    int sum=0;
    int maxj=0;
    for(int i=0;i<n;i++){
        int p; cin>>p;
        sum+=p;
        maxj=max(maxj,p);
    }
    cout<<sum-maxj/2<<endl;
    return 0;
}