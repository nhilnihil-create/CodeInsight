#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>>keiro(2,vector<int>(n));

    for(int i=0;i<n;i++){
        cin>>keiro.at(0).at(i);
    }
    for(int i=0;i<n;i++){
        cin>>keiro.at(1).at(i);
    }
    long int maxk=0;
    for(int k=0;k<n;k++){
        long int total=0;
        long int count=-1;
    
        for(int i=0;i<=k;i++){
            
            total+=keiro.at(0).at(i);
            count+=1;
        }
        for(int j=count;j<n;j++){
            total+=keiro.at(1).at(j);
        }
        maxk=max(maxk,total);
        
    }
    

    cout<<maxk<<endl;



}