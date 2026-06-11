#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,f,b=0,j=0,kaunto;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a.at(i);
    }
    sort(a.begin(),a.end());
    
    
    for(int i=0;i<n;i++){
        
        if(b<a.at(i)){
            b=a.at(i);
            j++;
        }
    }
    cout<<j<<endl;
}