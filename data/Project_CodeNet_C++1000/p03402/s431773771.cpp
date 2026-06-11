#include <iostream>
using namespace std;
int main(void){
    int a,b,c=0,m=0,n=0;
    string s[100],t[]={"....",".###",".#.#","####","#...","#.#."};
    cin>>a>>b;
    if(a>b)c=3;
    m=max(a,b);
    n=min(a,b);
    for(int i=0;i<100;i++){
        s[i]="";
        for(int j=0;j<25;j++){
            if(i%4==0||(i/4)*25+j>=m){
                s[i]+=t[0+c];
            }else if(i%4==2&&(i/4)*25+j<n-1){
                s[i]+=t[2+c];
            }else{
                s[i]+=t[1+c];
            }
        }
    }
    cout<<"100 100"<<endl;
    for(int i=0;i<100;i++){
        cout<<s[i]<<endl;
    }
}
