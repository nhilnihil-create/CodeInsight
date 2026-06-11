#include<bits/stdc++.h>
using namespace std;

int main(){
    map <int,int> times;
    times[1]=0;times[2]=0;times[3]=0;times[4]=0;
    for (int i=0; i<3; i++){
        int a,b; cin>>a>>b;
        times[a]+=1;
        times[b]+=1;
    }
    for(auto set:times){
        int time = set.second;
        if(time!=1 && time!=2){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}