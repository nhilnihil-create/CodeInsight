#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int s;
    cin >> s;
    int fnum = s%10;
    int snum = (s/10)%10;
    int tnum = (s/100)%10;
    
    if(tnum > snum){
        cout << tnum << tnum << tnum <<endl;
    }
    else if (tnum == snum){
        if(snum >= fnum){
            cout << tnum << tnum << tnum <<endl;
        }
        else{
            cout << tnum+1 << tnum+1 << tnum+1 << endl;
        }
    }
    else{
        cout << tnum+1 << tnum+1 << tnum+1 << endl;
    }
}