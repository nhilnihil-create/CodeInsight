#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int inputNum;
    cin >> inputNum;
    if (inputNum%100 >0 && inputNum%100<=12){
        if (inputNum/100<=12 && inputNum/100>0){
            cout<<"AMBIGUOUS"<<endl;
        }
        else if (inputNum/100>12 || inputNum/100<1){
            cout<<"YYMM"<<endl;
        }
    }else if (inputNum/100 >0 && inputNum/100<=12){
        if (inputNum%100<=12 && inputNum%100>0){
            cout<<"AMBIGUOUS"<<endl;
        }
        else if (inputNum%100>12 || inputNum%100==0){
            cout<<"MMYY"<<endl;
        }
    }else{
        cout<<"NA"<<endl;
    }
    return 0;
}

