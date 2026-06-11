#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>

using namespace std;

int main(){
    long int n,m,d,t;
    cin>>n;
    map<int,int>a;
    for(int i=0;i<n;i++){
        cin>>d;
        auto itr=a.find(d);
        if(itr!=a.end()){
            a[d]++;
        }else a[d]=1;
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>t;
        if(a[t]>0)a[t]--;
        else{
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
}