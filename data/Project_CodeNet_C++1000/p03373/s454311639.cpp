#include<bits/stdc++.h>
using namespace std;

int main(void){
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;

    int cost = 0;
    for(int i=0;i<=100000;i++){
        int j = max(x-i,0);
        int l = max(y-i,0);
        int tmp = a*j+b*l+2*c*i;
        if(cost>tmp || cost==0) cost = tmp;
    }

    cout << cost << endl;
}