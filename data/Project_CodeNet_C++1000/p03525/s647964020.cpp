#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;
using ll = long long;

int f(vector<bool> is, int i, vector<int>& time){
    if(i == 24){
        int last = -1;
        int res = 10000;
        for(int i = 0;i <= 23;i++){
            // cout<<is[i]<<" ";
            if(is[i] && last == -1){
                last = i;
            }else if(is[i]){
                res = min(res, i - last);
                // cout<<"!"<<i-last<<" ";
                last = i;
            }
        }
        if(last != -1)
        res = min(24 - last, res);
        // cout<<": "<<res<<endl;
        return res;
    }
    if(time[min(i,24-i)] == 0){
        is[i] = false;
        return f(is,i+1,time);
    }else if(time[min(i,24-i)] >= 2 || (i == 12 && time[i] == 1) || (i == 0 && time[i] == 1)){
        is[i] = true;
        return f(is,i+1,time);
    }else if(i > 12){
        is[i] = !is[24-i];
        return f(is,i+1,time);
    }else{
        is[i] = true;
        int x = f(is,i+1,time);
        is[i] = false;
        int y = f(is,i+1,time);
        return max(x,y);
    }

}

int main(){
    vector<int> time(13,0);
    int N;cin>>N;
    time[0]++;
    for(int i = 0;i < N;i++){
        int c;cin>>c;
        time[c]++;
        if(time[c]>=3){
            cout<<0<<endl;
            return 0;
        }
    }
    if(time[12] >= 2 || time[0]>=2){
        cout<<0<<endl;
        return 0;
    }
    int res = 0;
    
    vector<bool> is(24,false);
    cout<<f(is, 0, time)<<endl;
    

}