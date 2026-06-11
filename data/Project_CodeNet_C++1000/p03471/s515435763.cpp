#include<bits/stdc++.h>
using namespace std;
#define For(start,end) for(int i = (int)start;i<(int)end;i++)
using Int = long long int;
int main(){
    int N,Y;
    cin>>N>>Y;
    bool finish=false;
    int a=0,b=0;
    for(;a<=N;a++)
    {
        for(b=0;b<=N-a;b++)
        {
            if( 10000*a+5000*b+1000*(N-a-b)==Y){
                finish=true;
                break;
            }
    
        }
        if(finish){
            break;
        }
    
    }
    if(!finish)
    {
        cout<<-1<<" "<<-1<<" "<<-1<<endl;
    }
    else
    {
        cout<<a<<" "<<b<<" "<<(N-a-b)<<endl;
    }
    
}