#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,T;
    vector<int> c(1000),t(1000);
    cin >> N>>T;
    int cost=1000;
    bool isTLE=true;
    for(int i=0;i<N;i++){
        cin >> c.at(i)>>t.at(i);
        if(t.at(i)<=T){
            isTLE=false;
            if(cost>c.at(i)){
                cost=c.at(i);
            }

        }
    }
    if(isTLE==true){
        cout<<"TLE"<<endl;
        return 0;
    }
    cout<<cost<<endl;
    return 0;
}