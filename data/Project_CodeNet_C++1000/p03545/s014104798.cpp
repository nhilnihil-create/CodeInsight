#include <bits/stdc++.h>
using namespace std;
int main(){
    string x;
    cin >> x;
    int a,b,c,d;
    a = x[0]-48;
    b = x[1]-48;
    c = x[2]-48;
    d = x[3]-48;
    int s[4] = {a,b,c,d};
    for (int i=0; i<8; i++){
        int ans = s[0];
        int flag[3];
        for (int j=0; j<3; j++){
            if (i & (1<<j)){
                ans = ans - s[j+1];
                flag[j] = 1;
            }
            else{
                ans = ans + s[j+1];
                flag[j] = 0;
            }
        }
        if (ans == 7){
            //pythonだとintの第二引数で基数を指定することができるから下のようなやり方ができると思う。
            //cout<<a<<i[0]<<b<<i[1]<<c<<i[2]<<d<<i[3]<<endl
            cout<<a;
            if (flag[0]==0){
                cout<<'+';
            }else{
                cout<<'-';
            }
            cout<<b;
            if (flag[1]==0){
                cout<<'+';
            }else{
                cout<<'-';
            }
            cout<<c;
            if (flag[2]==0){
                cout<<'+';
            }else{
                cout<<'-';
            }
            cout<<d<<"=7"<<endl;
            return 0;
        }
    }
}