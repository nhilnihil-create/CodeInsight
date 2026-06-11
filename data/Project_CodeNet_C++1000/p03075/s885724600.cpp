#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> dis(5);
    int distant=0,k,cnt=0;
    for(auto &e:dis) cin >>e;
    cin >> k;
    for(int h=0;h<4;h++){
        for(int j=h+1;j<5;j++){
            if(dis[j]-dis[h]>k){
                cout <<":("<<endl;
                return 0;
            }
        }
        distant=0;
    }
    cout << "Yay!" <<endl;
}