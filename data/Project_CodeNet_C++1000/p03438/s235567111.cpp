#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    cin>>n;
    vector<long long> dis(n);
    vector<long long> a(n),b(n);
    
    for(long long i=0;i<n;i++){
        cin>>a.at(i);
    }
    for(long long i=0;i<n;i++){
        cin>>b.at(i);
        
        dis.at(i)=b.at(i)-a.at(i);
    }
    //できること
    //差を2減らして1増やす
    //差を1減らす
    
    sort(dis.begin(),dis.end());
    long long cnt=0;
    
    for(long long i=0;i<n;i++){
        if(dis.at(i)<0) cnt+=dis.at(i);
        else cnt+=dis.at(i)/2;
    }
    
    if(cnt>=0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    
    return 0;
}
