#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<tuple<int,int,int>> array(n+1);
    for(int i=0;i<n;i++){
        int t,x,y;
        cin >> t >> x >> y;
        tuple<int,int,int> d = make_tuple(t,x,y);
        array.at(i+1) = d;
    }

    bool flag = true;
    for(int i=0;i<n;i++){
        tuple<int,int,int> now = array.at(i);
        tuple<int,int,int> next = array.at(i+1);
        int dx_plus_dy = abs(get<1>(next) - get<1>(now)) + abs(get<2>(next) - get<2>(now));
        int dt = get<0>(next) - get<0>(now);
        int zan = -dx_plus_dy + dt;
        //cout << zan <<endl;
        if(zan < 0 || zan % 2 == 1){
            flag = false;
            break;
        }  
    }
    if(flag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

}