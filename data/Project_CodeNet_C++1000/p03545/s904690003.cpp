#include<bits/stdc++.h>
using namespace std;
char inc(int i){
    if(i==0)return '+';
    else return '-';
}
int main(){
    string s;
    cin >> s;
    int a=s[0]-'0';
    int b=s[1]-'0';
    int c=s[2]-'0';
    int d=s[3]-'0';
    int tmp;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                tmp=a+b+c+d;
                if(i==1)tmp-=2*b;
                if(j==1)tmp-=2*c;
                if(k==1)tmp-=2*d;
                if(tmp==7){
                    cout << a;
                    cout << inc(i);
                    cout << b;
                    cout << inc(j);
                    cout << c;
                    cout << inc(k);
                    cout << d;
                    cout << "=7";
                    return 0;
                }
            }
        }
    }
}