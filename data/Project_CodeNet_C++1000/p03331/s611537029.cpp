#include<bits/stdc++.h>
using namespace std;
int main (){
    int N;
    cin >> N;

    int ans=N;
    for(int a=1;a<N/2+1;a++){
        int dsa=0,dsb=0;
        int x=a,y=N-a;

        while(x!=0){
            dsa += x%10;
            x = x/10;
        }

        while(y!=0){
            dsb += y%10;
            y = y/10;
        }

        if(dsa+dsb<ans)ans=dsa+dsb;

    }

    cout << ans << endl;
}