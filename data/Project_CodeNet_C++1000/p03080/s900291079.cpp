
#include <iostream>
using namespace std;
int main(){
    int a,cnt_red=0,cnt_blue=0;
    cin>>a;
    char k;
    for(int i=0;i<a;i++){
        cin>>k;
        if(k=='R'){
            cnt_red++;
        }else{
            cnt_blue++;
        }
    }
    
    if(cnt_red>cnt_blue){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return 0;
}