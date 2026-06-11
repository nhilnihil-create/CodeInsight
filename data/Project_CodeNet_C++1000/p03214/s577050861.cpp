#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> frame(n);
    float ave=0;
    for(int i=0; i<n; i++){
        cin>>frame[i];
        ave += frame[i];
    }
    ave = ave/n;
    float std = frame[0];
    int ind = 0;
    for(int i=0; i<n; i++){
        float res = abs(frame[i]-ave);
        if(std>res){
            std = res;
            ind = i;
        }
    }
    cout << ind << endl;
}