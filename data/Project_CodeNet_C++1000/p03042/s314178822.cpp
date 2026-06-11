#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int s;
    cin>>s;
    int y1=s/100;
    int y2=s%100;
    if(y1>=1&&y1<=12){
        if(y2>=1&&y2<=12)cout<<"AMBIGUOUS"<<endl;
        else cout<<"MMYY"<<endl;
    }else{
        if(y2>=1&&y2<=12)cout<<"YYMM"<<endl;
        else cout<<"NA"<<endl;
    }
    return 0;
}