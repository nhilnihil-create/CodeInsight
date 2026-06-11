#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long int;

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    vector<int>c(n);
    vector<int>sa(n);
    for(int i=0;i<n;i++){
        cin>>v.at(i);

    }
    for(int i=0;i<n;i++){
        cin>>c.at(i);
        sa.at(i)=v.at(i)-c.at(i);
    }
    int total=0;
    for(int i=0;i<n;i++){
        if(sa.at(i)>0){
            total+=sa.at(i);


        }
    }
    cout<<total<<endl;
}