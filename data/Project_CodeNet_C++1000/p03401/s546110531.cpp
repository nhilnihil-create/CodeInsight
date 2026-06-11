#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main(){
    long long n;
    cin>>n;
    vector<long long> hoge(n);
    
    for(int i=0;i<n;i++) cin>>hoge.at(i);
    
    long long sum=0;
    
    hoge.insert(hoge.begin(),0);
    hoge.push_back(0);
    
    for(int i=0;i<n+1;i++){
        sum+=abs(hoge.at(i+1)-hoge.at(i));
    }
    
    
    
    for(int i=1;i<n+1;i++){
        long long a=hoge.at(i-1);
        long long b=hoge.at(i);
        long long c=hoge.at(i+1);
        if(a>c) swap(a,c);
        
        if(a<=b && b<=c) cout<<sum<<endl;
        else if(a<=b && c<=b) cout<<sum-abs(b-c)*2<<endl;
        else if(b<=a && b<=c) cout<<sum-abs(a-b)*2<<endl;
    }
    
    return 0;
}