#include<iostream>
using namespace std;

int main(){
    int N, x=0;
    cin>>N;
    int V[N], C[N];
    for (int i = 0; i < N; i++)
    {
        cin>>V[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin>>C[i];
    }
    for (int i = 0; i < N; i++)
    {
        if (V[i]>C[i])
        {
            x += V[i]-C[i];
        }
        
    }
    cout<<x<<endl;
    
    
}