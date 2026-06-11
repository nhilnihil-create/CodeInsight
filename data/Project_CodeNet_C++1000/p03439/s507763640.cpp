#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    int ub=N-1,lb=0;
    bool lM,uM,mM;
    string input;

    cout << 0 << endl;
    cin >> input;

    if(input == "Vacant"){
        return 0;
    }else if(input=="Male"){
        lM = true;
    }else{
        lM = false;
    }
 
    cout << N-1 << endl;
    cin >> input;

    if(input == "Vacant"){
        return 0;
    }else if(input=="Male"){
        uM = true;
    }else{
        uM = false;
    }

    while(ub-lb>1){
        int mid = (ub+lb)/2;

        cout << mid << endl;
        cin >> input;

        if(input == "Vacant"){
            return 0;
        }else if(input=="Male"){
            mM = true;
        }else{
            mM = false;
        }

        if(((mid-lb)%2==0 && lM!=mM) || ((mid-lb)%2==1 && lM==mM)){
            ub = mid;
            uM = mM;
        }else{
            lb = mid;
            lM = mM;
        }
    }
}
