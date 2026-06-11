#include <iostream>
using namespace std;
int main(void){
    string s;
    int i,j;
    cin >> s;
    for(i=0;i<8;i++){
        string siki;
        siki +=s[0];
        int tmp=(s[0]-'0');
        for(j=0;j<3;j++){
            if(i&(1<<j)){
                siki = siki + '+'+s[j+1];
                tmp = tmp +(s[j+1]-'0');
            }
            else{
                siki = siki + '-'+s[j+1];
                tmp = tmp-(s[j+1]-'0');
            }
        }
        if(tmp==7){
            cout << siki << "=7";
            return 0;
        }
    }
}