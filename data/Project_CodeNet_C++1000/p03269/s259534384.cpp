#include <iostream>
#include<math.h>
using namespace std;

int main(){
int L;
cin>>L;
int MAX=40000;
int edge[60][3];
int e[60];
e[0]=L;
int now=0,e_now=0;
while(e[now]/2>0){
    if(e[now]%2==1){
        edge[e_now][0]=now+1;
        edge[e_now][1]=MAX;
        edge[e_now][2]=e[now]-1;
        e_now++;
    }
    e[now+1]=e[now]/2;
    edge[e_now][0]=now+1;
    edge[e_now][1]=now+2;
    edge[e_now][2]=e[now+1];
    e_now++;
        edge[e_now][0]=now+1;
        edge[e_now][1]=now+2;
        edge[e_now][2]=0;
        e_now++;
    now++;
}

for(int i=0;i<e_now;i++){
    if(edge[i][1]==MAX){
        edge[i][1]=now+1;
    }
}
cout<<now+1<<" "<<e_now<<endl;
for(int i=0;i<e_now;i++){
    cout<<edge[i][0]<<" "<<edge[i][1]<<" "<<edge[i][2]<<" "<<endl;
}
}
