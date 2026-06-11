#include <bits/stdc++.h>
using namespace std;
int main(void){
    
    //*
    string a;
    int acnt = 0, bcnt = 0, ccnt = 0;
    cin >> a ;
    //*/
    
    if(a.at(0) == 'a'){
        acnt++;
    } else if (a.at(0) == 'b'){
        bcnt++;
    } else if (a.at(0) == 'c'){
        ccnt++;
    }
    
    if(a.at(1) == 'a'){
        acnt++;
    } else if (a.at(1) == 'b'){
        bcnt++;
    } else if (a.at(1) == 'c'){
        ccnt++;
    }
    
    if(a.at(2) == 'a'){
        acnt++;
    } else if (a.at(2) == 'b'){
        bcnt++;
    } else if (a.at(2) == 'c'){
        ccnt++;
    }
    
    /*
    vector<int> vec(4);
    cin >> vec.at(0) >> vec.at(1) >> vec.at(2) ;
    
    sort(vec.begin(), vec.end());
    */
    
    //*
    if(acnt == 1 && bcnt == 1 && ccnt == 1 ){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    //*/
    
    //cout << min(a, b) + min(c, d) << endl;

    return 0; 
}
