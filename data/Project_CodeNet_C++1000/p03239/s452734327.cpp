#include<bits/stdc++.h>

using namespace std;

int main()
{
    map<int,int>m;
    int c,t,N,T,a[101],idx;
    cin>>N>>T;
    for(int i=0;i<N;i++){
        cin>>c>>t;
        m[c]=t;
        a[i]=c;
    }
    sort(a,a+N);
    int chk=0;
    for(int i=0;i<N;i++){
            if(m[a[i]]<=T){
                idx=i;
                chk=1;
                break;
            }
        }
        if(chk==1)
        cout<<a[idx];
        else cout<<"TLE";
    return 0;
}
