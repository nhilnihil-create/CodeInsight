#include <bits/stdc++.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const ll BIG=1e15;

ll K;
ll d[100001];

int main(){
    cin>>K;
    d[1]=1;
    queue<int> Q;
    Q.push(1);

    while(!Q.empty()){
        int x=Q.front();
        int y=d[x];
        Q.pop();
        int A=x;
        while(true){
            A=(A*10)%K;
            if(d[A]!=0 && d[A]<=d[x]) break;
            d[A]=y;
            Q.push(A);
        }
        int B=(x+1)%K;
        if(d[B]==0) {Q.push(B); d[B]=y+1;}
    }
    //for(int i=0;i<K;i++) cout<<i<<' '<<d[i]<<endl;
    cout<<d[0]<<endl;

}