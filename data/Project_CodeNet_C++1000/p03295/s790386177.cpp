#include <bits/stdc++.h>
using namespace std;



int main(){
    int N,M,eastbridge,index=1,result=1;
    cin>>N>>M;
    vector<pair<int,int> > req(M);
    for(int i=0;i<M;i++){
        cin>>req.at(i).second>>req.at(i).first;
    }
    sort(req.begin(),req.end());
    eastbridge=req.at(0).first-1;
    while(index<M){
        if(req.at(index).second>eastbridge){
            result++;
            eastbridge=req.at(index).first-1;
        }
        index++;
    }
    cout<<result<<endl;
    
    
}