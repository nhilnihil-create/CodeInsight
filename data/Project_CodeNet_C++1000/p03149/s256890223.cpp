#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a(4);
    int i;
    int s1=0;
    int s2=0;
    int s3=0;
    int s4=0;
    for(i=0;i<4;i++){
        cin >> a.at(i);
        if(a.at(i)==1){
            s1++;
        }
        else if(a.at(i)==9){
            s2++;
        }
        else if(a.at(i)==7){
            s3++;
        }
        else if(a.at(i)==4){
            s4++;
        }
    }

    if((s1==1)&&(s2==1)&&(s3==1)&&(s4==1)){
        cout << "YES" << endl;
    }
    else{
        cout << "NO"<<endl;
    }
    return 0;
}