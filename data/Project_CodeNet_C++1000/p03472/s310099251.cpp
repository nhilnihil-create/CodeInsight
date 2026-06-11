#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
using namespace std;
int main(void){
    long long int n,h;
    cin>>n>>h;
    vector<int> a(n);
    vector<int> b(n);
    int amax=0;
    for(long long int i=0; i<n; i++){
        cin>>a.at(i)>>b.at(i);
        amax=max(amax,a.at(i));
    }
    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());
    
    long long int ans=0;
    long long int count=0;
    while(count<n){
        if(b.at(count)>=amax){
            ans++;
            h-=b.at(count);
            count++;
        }else{
            break;
        }
        if(h<=0) break;
    }
    if(h<=0) h=0;
    if(h%amax==0){
        ans+=h/amax;
    }else{
        ans+=h/amax;
        ans++;
    }
    cout<<ans<<endl;
}
