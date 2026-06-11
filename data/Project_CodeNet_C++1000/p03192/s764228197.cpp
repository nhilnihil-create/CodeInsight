#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin  >> n;
    vector<int> a(4);
    a.at(0)=n/1000;
    a.at(1)=n/100-a.at(0)*10;
    a.at(2)=n/10-a.at(0)*100-a.at(1)*10;
    a.at(3)=n%10;
    int i;
    int h=0;
    for(i=0;i<4;i++){
        if(a.at(i)==2){
            h++;
        }
    }
    cout << h << endl;

    return 0;
}