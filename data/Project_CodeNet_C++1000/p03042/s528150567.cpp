#include<iostream>

using namespace std;
int main(){
    int s;
    cin>>s;
    if(s/100>0 && s/100 < 13 && s%100 > 0 && s%100 <13 ){
        cout <<"AMBIGUOUS"<<endl;
    }
    else if(s/100>0 && s/100 < 13 ){
        cout << "MMYY" << endl;
        }else if(s%100 > 0 && s%100 <13){
            cout << "YYMM" <<endl;
        }else{
            cout << "NA" <<endl;
        }
    }