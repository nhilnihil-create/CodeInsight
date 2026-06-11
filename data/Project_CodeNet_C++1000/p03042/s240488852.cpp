#include<bits/stdc++.h>
using namespace std;

int main(){
    int s;
    cin >> s;
    int ans1 = s/100;
    int ans2 = s%100;
    if(1 <= ans1 && ans1 <= 12){
        if(1<=ans2 && ans2<=12){
            cout << "AMBIGUOUS" << endl;
        }else{
            cout << "MMYY" << endl;
        }
    }else{
        if(1 <= ans2 && ans2 <= 12){
            cout << "YYMM" << endl;
        }else{
            cout << "NA" << endl;
        }
    }
    return 0;

}