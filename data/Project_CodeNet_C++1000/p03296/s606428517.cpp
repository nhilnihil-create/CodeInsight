#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    int hanbetu=0,n;
    cin>>n;
    int sum=0,a,b=-1,c=0;
    rep(i,n){
        cin>>a;
        if(a==b){
            cerr<<"enter"<<endl;
            c++;
        }else{
            cerr<<"enter"<<endl;
            sum+=c/2;
            b=a;
            c=1;
        }
    }
    sum+=c/2;
    cout<<sum<<endl;
}