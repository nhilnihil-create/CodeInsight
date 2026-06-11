#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <iomanip>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>a(1000000);
    vector<int>b(1000000);
    cin>>a[0]>>b[0];
    for(int i=0;i<n;i++){
        cin>>a[i+1];
    }
     for(int i=0;i<=n;i++){
     	a[i]+=100;
    }
    for(int i=0;i<m;i++){
        cin>>b[i+1];
    }
    for(int i=0;i<=m;i++){
    	b[i]+=100;
    }
    sort(a.begin(),a.end(),greater<>());
    sort(b.begin(),b.end(),greater<>());
    if(a[0]>=b[m]){
        cout<<"War"<<endl;
    }
    else{
        cout<<"No War"<<endl;
    }
    return 0;
}