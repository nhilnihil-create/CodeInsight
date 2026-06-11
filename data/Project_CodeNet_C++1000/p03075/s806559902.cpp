#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int>a(5);
    int k;
    bool check=true;
    for(int i=0;i<5;i++) cin>>a.at(i);
    cin>>k;

    for(int i=0;i<5;i++){

        for(int j=i+1;j<5;j++){
            if(a.at(j)-a.at(i)>k) check=false;
        }


    }

    if(check) cout<<"Yay!"<<endl;
    else cout<<":("<<endl;


    return 0;
}