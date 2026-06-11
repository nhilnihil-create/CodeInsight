#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
    map<int,int> N;
    REP(i,4){
        int a;cin>>a;
        if(a==1||a==9||a==7||a==4)N[a]++;
        else {
            cout<<"NO"<<endl;
            return 0;
        }
        
    }
    cout<<(N.size()==4?"YES":"NO")<<endl;
}