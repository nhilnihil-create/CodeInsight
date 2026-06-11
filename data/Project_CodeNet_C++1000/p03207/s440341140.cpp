#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
//もっと簡単に
int main(){
    int n; cin>>n;
    vector<int> p(n);
    for(int i=0;i<n;i++) cin>>p[i];
    int maxp=0;
    int maxin=0;
    int ans=0;
    for(int i=0;i<n;i++){
        if(p[i]>maxp){
            maxp=p[i];
            maxin=i;
        }
        ans+=p[i];
    }
    cout<<ans-maxp/2<<endl;
    return 0;
}