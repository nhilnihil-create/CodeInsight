#include <iostream>

using namespace std;
int main(){
    string inp;
    cin >> inp;
    int a = (inp[0]-'0')*10+(inp[1]-'0') ,b =(inp[2]-'0')*10+(inp[3]-'0');
    if(a!=0 && b!=0){
        if(a<=12 && b>12){
            cout<< "MMYY";
        }
        else if(a>12 && b <=12){
            cout << "YYMM";
        }
        else if(a<=12 && b <= 12) {
            cout<< "AMBIGUOUS";
        }
        else if(a>12 && b > 12){
            cout<< "NA";
        }

    }
    else{
        if(a==0 &&b ==0){
            cout<<"NA";
        }
        else if(a==0 && b <=12){
            cout<< "YYMM";
        }
        else if(a<=12 && b==0){
            cout<< "MMYY";
        }
        
        else{
            cout<<"NA";
        }
    }
    return 0;
}
