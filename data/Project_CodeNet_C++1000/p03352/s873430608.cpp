#include <bits/stdc++.h>
using namespace std;

int main(void){
    int x,b,p,i,ans1000;
    i = 1;
    vector<int>  bekilist(1000,1001);
    bekilist.at(0) = 1;
    cin >> x;

    //list up
    for(b=2; b<33; b++){
        for(p=2; pow(b,p) <= 1000; p++){
            bekilist.at(i) = pow(b,p);
            i++;
        }
    }
    sort(bekilist.begin(),bekilist.end());

    //included x < 1000
    for(i=0; bekilist.at(i) <= 1000; i++){
        if(bekilist.at(i) > x){
            cout << bekilist.at(i-1) << endl;
            break;
        }
    }

    //x = 1000
    if(x == 1000){
        for(i=0; bekilist.at(i) != 1001; i++){
            ans1000 = bekilist.at(i);
        }
        cout << ans1000 << endl;
    }


    return 0;
}