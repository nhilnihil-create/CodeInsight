#include<iostream>
using namespace std;
int main()
{
    int a;
    cin>>a;
    if(a<1200) {
        cout<< "ABC"<<endl;
        return 0;
    }
    if(a==1200) {
        cout<< "ARC"<<endl;
        return 0;
    }

    if(a<2800){
        cout<< "ARC"<<endl;
        return 0;
    }
    if(a==2800) {
        cout<< "AGC"<<endl;
        return 0;}
    if(a<4800) {
        cout<< "AGC"<<endl;
        return 0;}


    return 0;
}

