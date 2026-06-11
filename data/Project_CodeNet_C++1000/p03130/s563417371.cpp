#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){

    int a = 0 , b = 0 , c = 0 , d = 0 , n = 6 ;
    for(int i = 0 ; i < n ; i ++ ){
        int h ;
        cin >> h ;
        if(h==1){
            a++;
        }
        if(h==2){
            b++;
        }
        if(h==3){
            c++;
        }
        if(h==4){
            d++;
        }
    }
    if(a>2 || b > 2 || c > 2 || d >2 ){
        cout<<"NO"<<endl;
        return 0 ;
    }
    cout<<"YES"<<endl;
    return 0;

}
