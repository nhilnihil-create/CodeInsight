#include <bits/stdc++.h>
using namespace std;


int main() {

    vector<int>  pos(5);
    cin>>pos.at(0)>>pos.at(1)>>pos.at(2)>>pos.at(3)>>pos.at(4);

    int k;
    cin>>k;

    bool flg=true;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(i!=j&&abs(pos.at(i)-pos.at(j))>k){
                flg=false;
                break;
            }
        }
    }

    if(flg)
        cout<<"Yay!"<<endl;
    else
        cout<<":("<<endl;


    return 0;
}