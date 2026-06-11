#include <iostream>
using namespace std;
typedef pair<int ,int > pp;

int N;

void swap(pp *kr,pp *kl){
    pp t=*kr;
    *kr=*kl;
    *kl=t;
}

void sortF( pp *a)
{  
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            if(a[i].first>a[j].first){
                swap(&a[i],&a[j]);
            }
        }
    }
}

void sortS(pp *a)
{   
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            if(a[i].second<a[j].second){
                swap(&a[i],&a[j]);
            }
        }
    }
}

int main()
{
    cin >> N;
    pp red[N], blue[N];
    for (int i = 0; i < N; i++)
    {
        cin >> red[i].first >> red[i].second;
    }
    for (int i = 0; i < N; i++)
    {
        cin >> blue[i].first >> blue[i].second;
    }
    sortS(red);
    sortF(blue);
    bool isUsed[N]={};
    int count =0;
    int MaxY=-1;
    int Max=0;
    for(int i=0;i<N;i++){
        MaxY=-1;
        Max=0;
        for(int j=0;j<N;j++){
            if((blue[i].first<=red[j].first)||(blue[i].second<=red[j].second)){
                continue;
            }
            if(isUsed[j]){
                continue;
            }
            count++;
            isUsed[j]=true;
            break;
        }
    }
    cout << count <<endl;
    return 0;
}