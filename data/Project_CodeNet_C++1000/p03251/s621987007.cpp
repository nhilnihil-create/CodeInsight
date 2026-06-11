#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    vector<int> xv(n);
    vector<int> yv(m);
    for(int i=0;i<n;i++){
        cin>>xv[i];
    }
    for(int i=0;i<m;i++){
        cin>>yv[i];
    }
    sort(xv.begin(),xv.end());
    sort(yv.begin(),yv.end());
    for(int i=xv.back()+1;i<=yv.front();i++){
       if(x<i&i<=y){
            cout<<"No War";
            return 0;
        } 
    }
    cout<<"War";
    
    return 0;
}