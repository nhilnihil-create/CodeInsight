#include <iostream>
#include<vector>
#define rep(i,n) for(int i = 0; i < (n); i++)

using namespace std;

int main() {
    vector<int>antena(5);
    rep(i,5)cin>>antena[i];
    int k;
    cin>>k;
    bool communicate=true;
    
    rep(i,5){
        rep(j,i){
            if(antena[i]-antena[j]>k){
                communicate=false;
                break;
            }
            if(!communicate)break;
        }
    }
    if(communicate)cout<<"Yay!"<<endl;
    else cout<<":("<<endl;
    return 0;
}