#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> time(5);
    int mod10 = 10;
    int index;
    
    for(int i=0; i<5; i++){
        cin>>time[i];
        if(time[i]%10 < mod10 && time[i]%10 != 0){
            mod10 = time[i]%10;
            index = i;
        }
    }

    for(int i=0; i<5; i++){
        if(i != index){
            if(time[i]%10 != 0){
                time[i] = time[i]-time[i]%10+10;
            }
        }
    }

    int ans = 0;
    for(int i=0; i<5; i++){
        //cout<< time[i] <<endl;
        ans += time[i];
    }

    cout<< ans <<endl;
    return 0;
}